char ** piso_matrix;
int ** visited_matrix;
int fila_inicio, columna_inicio;
int filas, columnas;
int key = 0;


enum simbols {
  camino,
  muro,
  escalera_bajar,
  escalera_subir,
  llave,
  tesoro,
  visitado, 
  inicio
};

void alloc_piso(){
  piso_matrix = malloc(filas * sizeof(char*));

  for(int i=0; i<filas; ++i){
    piso_matrix[i] = malloc(columnas * sizeof(char*));
  }
}

void alloc_visited(){
  visited_matrix = malloc(filas * sizeof(char*));

  for(int i=0; i<filas; i++){
    visited_matrix[i] = malloc(columnas * sizeof(char*));
  }
}

void get_piso(char * fileName, int piso_n, int ida){
  char c; 
  int len = 0;
  FILE * file = fopen(fileName, "r");

  if (file) {
    while((c = getc(file)) != EOF){
      //Assign filas first line
      if(len == 0){
        filas = c - '0';
      }
      //Columns second line
      else if(len == 2){
        columnas = c - '0';
        //Assign memory to matrix
        alloc_piso();

        //Create matrix
        // printf("Filas:%i\n", filas);
        // printf("columnas:%i\n", columnas);

        for(int i=0; i<filas; i++){
          for(int j=0; j<columnas; j++){
            c = getc(file);
            if(c == ' ' || c == '\n'){
              c = getc(file);
            }
            piso_matrix[i][j] = c;

            /* Cargando pisos de IDA */
            if(ida){
              if(piso_n == 1){
                if(c == 'I'){
                  fila_inicio = i;
                  columna_inicio = j;
                }
              }
              else if(piso_n == 2){
                if(key == 0){
                  if(c == 'B'){
                    fila_inicio = i;
                    columna_inicio = j;
                  }
                }
                else{
                  if(c == 'L'){
                    fila_inicio = i;
                    columna_inicio = j;
                  }
                } 
              }
              else if(piso_n == 3){
                if(c == 'B'){
                  fila_inicio = i;
                  columna_inicio = j;
                }
              }
            }
            /* Cargando pisos de VUELTA */
            else{
              if(piso_n == 3){
                if(c == 'T'){
                  fila_inicio = i;
                  columna_inicio = j;
                }
              }
              else if(piso_n == 2){
                if(c == 'S'){
                  fila_inicio = i;
                  columna_inicio = j;
                }
              }
              else if(piso_n == 1){
                if(c == 'S'){
                  fila_inicio = i;
                  columna_inicio = j;
                }
              }
            }
            
          }
        }
        fclose(file);
      }
      len++;
    }
  }
}

void set_visited(int piso_n, int ida){
  alloc_visited();

  for(int i=0; i<filas; i++){
    for(int j=0; j<columnas; j++){
      if(ida){
        if(piso_n == 1){
          if(piso_matrix[i][j] == 'I'){
            visited_matrix[i][j] = camino; //Inicio
            piso_matrix[i][j] = '.';
          }
        }
        if(key == 0 && piso_n==2){
          if(piso_matrix[i][j] == 'I' || piso_matrix[i][j] == 'B'){
            visited_matrix[i][j] = camino; //Inicio
            piso_matrix[i][j] = '.';
          }
        }
        if(key == 1 && piso_n==2){
          if(piso_matrix[i][j] == 'L'){
            visited_matrix[i][j] = camino; //Inicio
            piso_matrix[i][j] = '.';
          }
        } 
        if(key == 1 && piso_n==3){
          if(piso_matrix[i][j] == 'B'){
            visited_matrix[i][j] = camino;
            piso_matrix[i][j] = '.';
          }
        }
      }
      else{
        if(piso_n == 3){
          if(piso_matrix[i][j] == 'T'){
            visited_matrix[i][j] = camino;
            piso_matrix[i][j] = '.';
          }
        }
        else if(piso_n == 2){
          if(piso_matrix[i][j] == 'S'){
            visited_matrix[i][j] = camino;
            piso_matrix[i][j] = '.';
          }
        }
        else if(piso_n == 1){
          if(piso_matrix[i][j] == 'S'){
            visited_matrix[i][j] = camino;
            piso_matrix[i][j] = '.';
          }
        }
      }
      if(piso_matrix[i][j] == 'C'){
        visited_matrix[i][j] = camino;
      }
      else if(piso_matrix[i][j] == 'M'){
        visited_matrix[i][j] = muro;
      }
      else if(piso_matrix[i][j] == 'S'){
        visited_matrix[i][j] = escalera_subir;
      }
      else if(piso_matrix[i][j] == 'L'){
        visited_matrix[i][j] = llave;
      }
      else if(piso_matrix[i][j] == 'B'){
        visited_matrix[i][j] = escalera_bajar;
      }
      else if(piso_matrix[i][j] == 'T'){
        visited_matrix[i][j] = tesoro;
      }
      else if(piso_matrix[i][j] == 'I'){
        visited_matrix[i][j] = inicio;
      }
    }
  }
}

void print_piso(){
  printf("\n---------- \n");
  printf("\n");
  printf("Piso: \n");
  printf("\n");

  for(int i=0; i<filas; i++){
    for(int j=0; j<columnas; j++){
      printf("%c ", piso_matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void print_visited(){
  printf("\n---------- \n");
  printf("\n");
  printf("Visited : \n");
  printf("\n");

  for(int i=0; i<filas; i++){
    for(int j=0; j<columnas; j++){
      printf("%i ", visited_matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void add_visited(){
  for(int i=0; i<filas; i++){
    for(int j=0; j<columnas; j++){
      if(piso_matrix[i][j] != 'I'){
        if(visited_matrix[i][j] == visitado){
          piso_matrix[i][j] = '.';
        }
      }
    }
  }
}

void free_memory(){
  free(piso_matrix);	
	free(visited_matrix);
}

int write_txt(int fila, int columna, int piso, char mov, char objetivo, FILE* fp){
  // printf("fila:%i\n", fila);
  // printf("columna:%i\n", columna);
  
  if(fila < 0 || columna < 0 || fila >= filas || columna >= columnas){
    printf("Descartando... \n");
    return 0;
  }

  char* actual = &piso_matrix[fila][columna];
  // printf("actual:%c\n\n", *actual);

  if(*actual==objetivo){
    if(objetivo == 'S' && piso==1){
      fprintf(fp, "Se ha hallado la escalera para subir al piso %i!\n", piso+1);
    }
    if(piso == 2){
      if(objetivo=='L'){
        fprintf(fp, "Se ha hallado la llave para el tesoro!.\n");
      }
      if(objetivo=='S'){
        fprintf(fp, "Se ha hallado la escalera para subir al piso %i!\n", piso+1);
      }
      if(objetivo=='B'){
        fprintf(fp, "Se ha hallada la escalera para bajar al piso %i\n", piso-1);
      }
    }
    if(piso == 3){
      if(objetivo=='T'){
        fprintf(fp, "Se ha hallado el tesoro!\n\n");
      }
      if(objetivo=='B'){
        fprintf(fp, "Se ha hallado la escalera para bajar al piso %i.", piso-1);
      }
    }
    return 1;
  }

  if(*actual=='.'){
    *actual='v';
    printf("mov: %c \n \n", mov);
    //Escribir archivo de texto
    if(mov=='L'){
      fprintf(fp, "Me moví hacia la izquierda\n");
    }
    if(mov=='R'){
      fprintf(fp, "Me moví hacia la derecha\n");
    }
    if(mov=='U'){
      fprintf(fp, "Me moví hacia arriba\n");
    }
    if(mov=='D'){
      fprintf(fp, "Me moví hacia abajo\n");
    }

    if(write_txt(fila, columna-1, piso, 'L', objetivo, fp)){
      return 1;
    }
    if(write_txt(fila+1, columna, piso, 'D', objetivo, fp)){
      return 1;
    }
    if(write_txt(fila, columna+1, piso, 'R', objetivo, fp)){
      return 1;
    }
    if(write_txt(fila-1, columna, piso, 'U', objetivo, fp)){
      return 1;
    }
  }
  else{
    return 0;
  }
} 
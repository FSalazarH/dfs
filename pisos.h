char ** piso;
int ** visited;
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
  visitado
};

void alloc_piso(){
  piso = malloc(filas * sizeof(char*));

  for(int i=0; i<filas; ++i){
    piso[i] = malloc(columnas * sizeof(char*));
  }
}

void alloc_visited(){
  visited = malloc(filas * sizeof(char*));

  for(int i=0; i<filas; i++){
    visited[i] = malloc(columnas * sizeof(char*));
  }
}

void get_piso(char * fileName, int piso_n){
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
        printf("Filas:%i\n", filas);
        printf("columnas:%i\n", columnas);

        for(int i=0; i<filas; i++){
          for(int j=0; j<columnas; j++){
            c = getc(file);
            if(c == ' ' || c == '\n'){
              c = getc(file);
            }
            piso[i][j] = c;
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
            
          }
        }
        fclose(file);
      }
      len++;
    }
  }
}

void set_visited(){
  alloc_visited();

  for(int i=0; i<filas; i++){
    for(int j=0; j<columnas; j++){
      if(key == 0){
        if(piso[i][j] == 'I' || piso[i][j] == 'B'){
          visited[i][j] = camino; //Inicio
          piso[i][j] = '.';
        }
      }
      if(key == 1){
        if(piso[i][j] == 'L'){
          visited[i][j] = camino; //Inicio
          piso[i][j] = '.';
        }
      } 
      if(piso[i][j] == 'C'){
        visited[i][j] = camino;
      }
      else if(piso[i][j] == 'M'){
        visited[i][j] = muro;
      }
      else if(piso[i][j] == 'S'){
        visited[i][j] = escalera_subir;
      }
      else if(piso[i][j] == 'L'){
        visited[i][j] = llave;
      }
      else if(piso[i][j] == 'B'){
        visited[i][j] = escalera_bajar;
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
      printf("%c ", piso[i][j]);
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
      printf("%i ", visited[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void add_visited(){
  for(int i=0; i<filas; i++){
    for(int j=0; j<columnas; j++){
      if(piso[i][j] != 'I'){
        if(visited[i][j] == visitado){
          piso[i][j] = '.';
        }
      }
    }
  }
}

void free_memory(){
  free(piso);	
	free(visited);
}
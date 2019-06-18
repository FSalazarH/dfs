int dfs(int fila, int columna, int piso){
  // printf("\n");
  // printf("Entrando a dfs\n");
  // printf("Fila:%i\n", fila);
  // printf("columna:%i\n", columna);
  if(piso == 1){
    if(fila < 0 || columna < 0 || fila > filas-1 || columna > columnas-1){
      return 0;
    }
    int* actual = &visited[fila][columna];

    if(*actual == escalera_subir){
      return 1;
    }

    if(*actual == camino){
      *actual = muro;
      if(dfs(fila, columna-1, piso)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila+1, columna, piso)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila, columna+1, piso)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila-1, columna, piso)){
        *actual = visitado;
        return 1;
      }
    }
    return 0;
  }

  if(piso==2 && key==0){
    // printf("Estamos encontrando la llave!\n");
    // printf("\n");
    // printf("Fila:%i\n", fila);
    // printf("columna:%i\n", columna);
    if(fila < 0 || columna < 0 || fila > filas-1 || columna > columnas-1){
      return 0;
    }
    int* actual = &visited[fila][columna];
    // printf("actual:%i\n", *actual);

    if(*actual == llave){
      return 1;
    }

    if(*actual == camino){
      *actual = muro;
      if(dfs(fila, columna-1, piso)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila+1, columna, piso)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila, columna+1, piso)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila-1, columna, piso)){
        *actual = visitado;
        return 1;
      }
    }
    return 0;
    
  }

  if(piso==2 && key==1){
    // printf("Estamos encontrando la escalera para subir!\n");
    // printf("\n");
    // printf("Fila:%i\n", fila);
    // printf("columna:%i\n", columna);
    if(fila < 0 || columna < 0 || fila > filas-1 || columna > columnas-1){
      return 0;
    }
    int* actual = &visited[fila][columna];
    // printf("actual:%i\n", *actual);

    if(*actual == escalera_subir){
      return 1;
    }

    if(*actual == camino){
      *actual = muro;
      if(dfs(fila, columna-1, piso)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila+1, columna, piso)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila, columna+1, piso)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila-1, columna, piso)){
        *actual = visitado;
        return 1;
      }
    }
    return 0;
  }

  if(piso==3){
    printf("Estamos encontrando el tesoro!\n");
    printf("\n");
    printf("Fila:%i\n", fila);
    printf("columna:%i\n", columna);
    if(fila < 0 || columna < 0 || fila > filas-1 || columna > columnas-1){
      return 0;
    }
    int* actual = &visited[fila][columna];
    printf("actual:%i\n", *actual);

    if(*actual == tesoro){
      return 1;
    }

    if(*actual == camino){
      *actual = muro;
      if(dfs(fila, columna-1, piso)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila+1, columna, piso)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila, columna+1, piso)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila-1, columna, piso)){
        *actual = visitado;
        return 1;
      }
    }
    return 0;
  }
}
int dfs(int fila, int columna, char objetivo){

    if(fila < 0 || columna < 0 || fila > filas-1 || columna > columnas-1){
      return 0;
    }
    
    int* actual = &visited_matrix[fila][columna];

    if(*actual == objetivo){
      return 1;
    }

    if(*actual == camino){
      *actual = muro;
      if(dfs(fila, columna-1, objetivo)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila+1, columna, objetivo)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila, columna+1, objetivo)){
        *actual = visitado;
        return 1;
      }
      if(dfs(fila-1, columna, objetivo)){
        *actual = visitado;
        return 1;
      }
    }
    return 0;
  }

    

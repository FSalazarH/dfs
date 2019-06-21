#include <stdio.h>
#include <stdlib.h>

#include "pisos.h"
#include "busqueda.h"

int main()
{
  //Recorrer primer piso
  int piso = 1;
  int ida = 1;
  get_piso("pisos/piso1.txt", piso, ida);
  set_visited(piso, ida);
  print_piso();
  //print_visited();
  //Encontrar el camino hacia la escalera de subida usando DFS.
  dfs(fila_inicio, columna_inicio, escalera_subir);
  add_visited();
  //Imprimiendo el camino del primer piso para llegar a la escalera.
  print_piso();
  FILE * fp;
  fp = fopen ("camino/camino.txt","w");
  fprintf(fp, "Ida: \n\n");
  fprintf(fp, "Piso 1: Hallando la escalera para subir al piso 2.\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'S', fp);
  fclose(fp);

  /* PISO 2, BUSCANDO LLAVE */

  free_memory();
  piso = 2;
  get_piso("pisos/piso2.txt", piso, ida);
  set_visited(piso, ida);
  print_piso();
  //print_visited();
  dfs(fila_inicio, columna_inicio, llave);
  add_visited();
  print_piso();
  FILE * fp1;
  fp1 = fopen ("camino/camino.txt","a");
  fprintf(fp1, "\nPiso 2: Hallando la llave del tesoro\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'L', fp1);
  fclose(fp1);

  /* PISO 2, BUSCANDO ESCALERA PARA SUBIR */
  
  free_memory();
  key = 1; //Se asume que se encontró la llave
  get_piso("pisos/piso2.txt", piso, ida);
  set_visited(piso, ida);
  print_piso();
  //print_visited();
  dfs(fila_inicio, columna_inicio, escalera_subir);
  add_visited();
  print_piso();
  FILE * fp2;
  fp2 = fopen ("camino/camino.txt","a");
  fprintf(fp2, "\nPiso 2: Hallando la escalera de subida hacia el piso 3.\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'S', fp2);
  fclose(fp2);


  /* PISO 3, Buscando el TESORO */
  free_memory();
  piso = 3;
  get_piso("pisos/piso3.txt", piso, ida);
  set_visited(piso, ida);
  print_piso();
  //print_visited();
  dfs(fila_inicio, columna_inicio, tesoro);
  add_visited();
  print_piso();
  FILE * fp3;
  fp3 = fopen ("camino/camino.txt","a");
  fprintf(fp3, "\nPiso 3: Hallando el cofre del tesoro.\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'T', fp3);
  fclose(fp3);


  /* BAJADA */

  // Piso 3 al piso 2
  free_memory();
  piso = 3;
  ida = 0; //bajada
  get_piso("pisos/piso3.txt", piso, ida);
  set_visited(piso, ida);
  print_piso();
  dfs(fila_inicio, columna_inicio, escalera_bajar);
  add_visited();
  print_piso();
  FILE * fp4;
  fp4 = fopen ("camino/camino.txt","a");
  fprintf(fp4, "-------------\n");
  fprintf(fp4, "Vuelta: \n\n");
  fprintf(fp4, "\nPiso 3: Hallando la escalera de bajada al piso 2.\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'B', fp4);
  fclose(fp4);


  //Piso 2 al piso 1
  free_memory();
  piso = 2;
  get_piso("pisos/piso2.txt", piso, ida);
  set_visited(piso, ida);
  print_piso();
  dfs(fila_inicio, columna_inicio, escalera_bajar);
  add_visited();
  print_piso();
  FILE * fp5;
  fp5 = fopen ("camino/camino.txt","a");
  fprintf(fp5, "\n\nPiso 2: Hallando la escalera de bajada al piso 1.\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'B', fp5);
  fclose(fp5);

  //Piso 1 a la salida -> Origen, termina
  free_memory();
  piso = 1;
  get_piso("pisos/piso1.txt", piso, ida);
  set_visited(piso, ida);
  print_piso();
  dfs(fila_inicio, columna_inicio, inicio);
  add_visited();
  print_piso();
  FILE * fp6;
  fp6 = fopen ("camino/camino.txt","a");
  fprintf(fp6, "\n\nPiso 1: Hallando la salida de la torre.\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'I', fp6);
  fprintf(fp6, "\n\n Ha salido de la torre con el tesoro!");
  fclose(fp6);
}
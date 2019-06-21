#include <stdio.h>
#include <stdlib.h>

#include "pisos.h"
#include "dfs.h"

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
  fp = fopen ("/output/camino.txt","w");
  fprintf(fp, "Ida: \n\n");
  fprintf(fp, "Piso 1: Hallando la escalera para subir al piso 2.\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'S', fp);

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
  fprintf(fp, "\nPiso 2: Hallando la llave del tesoro\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'L', fp);

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
  fprintf(fp, "\nPiso 2: Hallando la escalera de subida hacia el piso 3.\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'S', fp);


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
  fprintf(fp, "\nPiso 3: Hallando el cofre del tesoro.\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'T', fp);


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
  fprintf(fp, "-------------\n");
  fprintf(fp, "Vuelta: \n\n");
  fprintf(fp, "\nPiso 3: Hallando la escalera de bajada al piso 2.\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'B', fp);


  //Piso 2 al piso 1
  free_memory();
  piso = 2;
  get_piso("pisos/piso2.txt", piso, ida);
  set_visited(piso, ida);
  print_piso();
  dfs(fila_inicio, columna_inicio, escalera_bajar);
  add_visited();
  print_piso();
  fprintf(fp, "\n\nPiso 2: Hallando la escalera de bajada al piso 1.\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'B', fp);

  //Piso 1 a la salida -> Origen, termina
  free_memory();
  piso = 1;
  get_piso("pisos/piso1.txt", piso, ida);
  set_visited(piso, ida);
  print_piso();
  dfs(fila_inicio, columna_inicio, inicio);
  add_visited();
  print_piso();
  fprintf(fp, "\n\nPiso 1: Hallando la salida de la torre.\n\n");
  write_txt(fila_inicio, columna_inicio, piso, 'a', 'I', fp);
  fprintf(fp, "\n\n Ha salido de la torre con el tesoro!");
}
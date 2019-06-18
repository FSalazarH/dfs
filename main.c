#include <stdio.h>
#include <stdlib.h>

#include "pisos.h"
#include "dfs.h"


int main()
{
  //Recorrer primer piso
  int piso = 1;
  get_piso("pisos/piso1.txt", piso);
  set_visited(piso);
  print_piso();
  print_visited();
  //Encontrar el camino hacia la escalera de subida usando DFS.
  dfs(fila_inicio, columna_inicio, piso);
  add_visited();
  //Imprimiendo el camino del primer piso para llegar a la escalera.
  print_piso();


  /* PISO 2, BUSCANDO LLAVE */

  free_memory();
  piso = 2;
  get_piso("pisos/piso2.txt", piso);
  set_visited(piso);
  print_piso();
  print_visited();
  dfs(fila_inicio, columna_inicio, piso);
  add_visited();
  print_piso();

  /* PISO 2, BUSCANDO ESCALERA PARA SUBIR */
  
  free_memory();
  key = 1; //Se asume que se encontró la llave
  get_piso("pisos/piso2.txt", piso);
  set_visited(piso);
  print_piso();
  print_visited();
  dfs(fila_inicio, columna_inicio, piso);
  add_visited();
  print_piso();


  /* PISO 3, Buscando el TESORO */
  free_memory();
  piso = 3;
  get_piso("pisos/piso3.txt", piso);
  set_visited(piso);
  print_piso();
  print_visited();
  dfs(fila_inicio, columna_inicio, piso);
  add_visited();
  print_piso();

}
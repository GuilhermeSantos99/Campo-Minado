#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "minefield.h"

int main() {

  inicializarJogo();
  sortearBombas(10);
  contarBombas();
  printf("\n\t\t\tCAMPO MINADO\n");
  imprimir();

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "minefield.h"

Celula jogo[10][10];
int l, c, tam = 10;

void inicializarJogo() {
  for (l = 0; l < tam; l++) {
    for (c = 0; c < tam; c++) {
      jogo[l][c].eBomba = 0;
      jogo[l][c].estaAberta = 0;
      jogo[l][c].vizinhos = 0;
    }
  }
}

void sortearBombas(int n) {
  int i;
  srand(time(NULL));
  for (i = 1; i <= n; i++) {
    l = rand() % tam;
    c = rand() % tam;

    if (jogo[l][c].eBomba == 0) {

      jogo[l][c].eBomba = 1;
    } else {
      i--;
    }
  }
}

int coordenadaValida() {
  if (l >= 0 && l < tam && c >= 0 && c < tam) {
    return 1;
  } else {
    return 0;
  }
}

int quantBombasVizinhas(int l, int c) {
  int quantidade = 0;

  if (coordenadaValida(l - 1, c) && jogo[l - 1][c].eBomba) {
    quantidade++;
  }
  if (coordenadaValida(l + 1, c) && jogo[l + 1][c].eBomba) {
    quantidade++;
  }
  if (coordenadaValida(l, c + 1) && jogo[l][c + 1].eBomba) {
    quantidade++;
  }
  if (coordenadaValida(l, c - 1) && jogo[l][c - 1].eBomba) {
    quantidade++;
  }
  return quantidade;
}

void contarBombas() {
  for (l = 0; l < tam; l++) {
    for (c = 0; c < tam; c++) {
      jogo[l][c].vizinhos = quantBombasVizinhas(l, c);
    }
  }
}

void imprimirLinha() {
  printf(
      "\n\t   ------------------------------------------------------------\n");
}

void imprimir() {
  printf("\n\n\t   ");

  for (l = 0; l < tam; l++) {

    printf(" %d    ", l);
  }
  imprimirLinha();

  for (l = 0; l < tam; l++) {
    printf("\t%d  |", l);
    for (c = 0; c < tam; c++) {
      if (jogo[l][c].estaAberta) {

        if (jogo[l][c].eBomba) {
          printf(" * ");
        } else {
          printf(" %d ", jogo[l][c].vizinhos);
        }

      } else {
        printf("   ");
      }

      printf(" | ");
    }
    imprimirLinha();
  }
}
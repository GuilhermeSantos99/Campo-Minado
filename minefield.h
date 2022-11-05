#ifndef MINEFIELD_H_INCLUDED
#define MINEFIELD_H_INCLUDED

typedef struct {
  int eBomba;
  int estaAberta;
  int vizinhos;
} Celula;


void inicializarJogo();

void sortearBombas(int n);

int coordenadaValida();

int quantBombasVizinhas(int l, int c);

void contarBombas();

void imprimirLinha();

void imprimir();

#endif
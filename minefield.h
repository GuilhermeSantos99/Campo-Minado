#ifndef MINEFIELD_H_INCLUDED
#define MINEFIELD_H_INCLUDED

typedef struct {
  int eBomba;
  int estaAberta;
  int vizinhos;
} Celula;

void inicializarJogo();

void sortearBombas(int n);

void contarBombas();

void imprimir();

void imprimirLinha();

#endif // MINEFIELD_H_INCLUDED
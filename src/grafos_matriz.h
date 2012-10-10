/*
  Grafos

  Grafos implementados por meio de matriz de adjacência.

  Criação: 09/10/12
  Autor: Sandro Miccoli

*/


#ifndef GRAFOS_H_
#define GRAFOS_H_

#include "matriz.h"


// Estrutura básica de um grafo, contendo seu número de vértices, arestas e um ponteiro para sua matriz de adjacência.
struct grafo {
    Matriz matrizesAdj;
    int N; // Quantidade de cidades no grafo
    int Vol[]; // Volume de pedidos de cada cidade
};

// Um objeto Grafo contém o endereço de um grafo
typedef struct grafo *Grafo;

// Inicializa grafo
Grafo inicializaGrafo(int V);


#endif /* GRAFOS_H_ */

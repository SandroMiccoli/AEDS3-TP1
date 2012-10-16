/*
  Grafos

  Grafos implementados por meio de matriz de adjacência.

  Criação: 09/10/12
  Autor: Sandro Miccoli

*/


#ifndef GRAFOS_H_
#define GRAFOS_H_

#include "matriz.h"

/*

TODO:

    Criar matriz de distância
    Preencher volume de pedidos
    Associar a matriz ao grafo no main

*/

// Estrutura básica de um grafo, contendo seu número de vértices, arestas e um ponteiro para sua matriz de adjacência.
struct grafo {
    Matriz matrizAdj;
    int N; // Quantidade de cidades no grafo
    int *Vol; // Volume de pedidos de cada cidade
};

// Um objeto Grafo contém o endereço de um grafo
typedef struct grafo Grafo;

// Inicializa grafo
void inicializaGrafo(FILE * arquivo, Grafo * G);


#endif /* GRAFOS_H_ */

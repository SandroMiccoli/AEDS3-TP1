/*
  Grafos

  Grafos implementados por meio de listas de adjacência.

  Criação: 07/10/12
  Autor: Sandro Miccoli

*/


#ifndef GRAFOS_H_
#define GRAFOS_H_

// Definição de ptr, que é um ponteiro para o próximo nó da lista.
typedef struct node *ptr;

// Estrutura básica de um grafo, contendo seu número de vértices, arestas e um ponteiro para sua lista de adjacência.
struct grafo {
    int V; // Quantidade de vértices no grafo
    int A; // Quantidade de arestas no grafo
    ptr *adj;
};

// Um objeto Grafo contém o endereço de um grafo
typedef struct grafo *Grafo;

// Estrutura de um vértice na aresta com sua distância para o próximo vértices
struct node{
    int v; // Vértice
    int d; // Distância
    ptr prox;
};

// Inicializa grafo
Grafo inicializaGrafo(int V);

// Cria um novo ponteiro de vertice v, distância d e apontador pro próximo nó prox
ptr novoNode(int v, int d, ptr prox);

// Insere uma aresta nova no grafo, ligando os vértices v e w.
void insereAresta(Grafo G, int v, int w, int d);

// Imprime o grafo, na ordem que foi inserido
void imprimeGrafo(Grafo G);


#endif /* GRAFOS_H_ */

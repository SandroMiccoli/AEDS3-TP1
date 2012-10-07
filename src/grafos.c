/*
  Grafos

  Grafos implementados por meio de listas de adjacência.

  Criação: 07/10/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

// Inicializa o grafo
Grafo inicializaGrafo(int V){
    Grafo G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = malloc(V * sizeof(ptr));
    for (int v=0; v < V; v++){
        G->adj[v] = NULL;
    }
    return G;
};

ptr novoNode(int v, int d, ptr prox){
    ptr x = malloc(sizeof *x);
    x->v = v;
    x->d = d;
    x->prox = prox;
    return x;
}

void insereArestaA(Grafo G, int v, int w, int d){
    if (v == w) return;
    G->adj[v] = novoNode(w, d, G->adj[v]);
    G->A++;
}

void insereAresta(Grafo G, int v, int w, int d){
    insereArestaA(G,v,w,d);
    //insereArestaA(G,w,v,d);
}

void imprimeGrafo(Grafo G){
    ptr p;
    for (int i=0; i < G->V; i++){
        for (p = G->adj[i]; p != NULL; p = p->prox){
            //printf("V: %d W: %d D: %d \t",p->v,i, p->d);
            printf("%d ",p->d);
        }
        printf("\n");
    }

}



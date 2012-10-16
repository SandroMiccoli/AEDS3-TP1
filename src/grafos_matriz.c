/*
  Grafos

  Grafos implementados por meio de matriz de adjacência.

  Criação: 09/10/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include "grafos_matriz.h"
#include "matriz.h"

// Inicializa o grafo
void inicializaGrafo(FILE * arquivo, Grafo * G){
    int num;


   leMatriz(arquivo, &(G->matrizAdj)); // Lê matrizes do arquivo e as insere na variável de matrizAjd

   G->N = G->matrizAdj.col;  // Atribui a quantidade N de cidades no grafo

   G->Vol = (int *) malloc (G->N * sizeof(int));

   for (int i = 0; i < G->N; i++){
        fscanf(arquivo,"%d ",&num);
        G->Vol[i] = num;
   }

};

// Imprime o grafo
void imprimeGrafo(Grafo G){

    //Imprime número de cidades
    printf("%d\n",G.N);

    imprimeMatriz(G.matrizAdj);

    for (int i = 0; i < G.N; i++){
        printf("%d ",G.Vol[i]);
    }
    printf("\n");

};


void freeGrafo(Grafo G){

    destroiMatriz(&(G.matrizAdj));

    free(G.Vol);

}

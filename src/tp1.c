/*
  Trabalho Prático 1 - Grafos

  Escolher a melhor cidade para instalar uma filial da empresa Atlanticon.

  Criação: 6/10/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "grafos_matriz.h"
#include "matriz.h"

int main(int argc, char *argv[]){


    if (argc == 3){ // Nome do arquivo (argv[0]) mais os dois parâmetros

        char entrada[40] = "entrada/";
        char saida[40] = "saida/";
        int k,n; // Instâncias de matrizes
        int dist;

        Grafo G;

        strcat(entrada,argv[1]);
        strcat(saida,argv[2]);

        FILE * inp = abreArquivoLeitura(entrada);
        FILE * out = abreArquivoEscrita(saida);

        fscanf(inp, "%d ", &k); // Lê as k instâncias de problemas

        //fscanf(inp, "%d ", &n); // Lê as n cidades

        //G = inicializaGrafo(n);

        //Matriz matrizAdj;

        printf("INSTANCIAS: %d\n\n",k);

        inicializaGrafo(inp, &G);

        //leMatriz(inp, &(G.matrizAdj)); // Lê matrizes do arquivo e as insere na variável de matrizAjd

        imprimeMatriz(G.matrizAdj);


       for (int i = 0; i < G.N; i++){
            printf("%d ",G.Vol[i]);
       }

        //insereAresta(G,i,j,dist);
   //     imprimeGrafo(G);

        destroiMatriz(&(G.matrizAdj));
        fechaArquivo(inp);
        fechaArquivo(out);

    }
    else{
        printf("Número incorreto de parâmetros. Fazer seguir exemplo:\n\n\t./tp1 input.txt output.txt\n\n"); exit(0);
    }
    return 0;
}

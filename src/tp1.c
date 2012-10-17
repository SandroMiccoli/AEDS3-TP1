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
#include "dijkstra.h"
#include "consultoria.h"

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

        for (int l=0; l<k; l++){

            inicializaGrafo(inp, &G);

            dijkstra_all(G);

            printf("CEN 1: %d\n",cenarioUm(G));
            printf("CEN 2: %d\n",cenarioDois(G));
            printf("CEN 3: %d\n",cenarioTres(G));

            freeGrafo(G);
        }



        fechaArquivo(inp);
        fechaArquivo(out);

    }
    else{
        printf("Número incorreto de parâmetros. Fazer seguir exemplo:\n\n\t./tp1 input.txt output.txt\n\n"); exit(0);
    }
    return 0;
}

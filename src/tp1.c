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
#include "grafos.h"

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

        fscanf(inp, "%d ", &n); // Lê as n cidades

        G = inicializaGrafo(n);

        printf("INSTANCIAS: %d\nCIDADES: %d\n\n",k,n);

        for (int i=0; i < n; i++){
            for (int j=0; j < n; j++){

                fscanf(inp, "%d", &dist);

               // if (j < i+1){  // Condição para trabalhar apenas com a diagonal inferior da matriz de adjacência
                    //printf("%d (%d,%d) ", dist,i,j);
                    printf("%d ", dist);
                    insereAresta(G,i,j,dist);
               // }
            }
            printf("\n");
        }
        printf("\n");
        imprimeGrafo(G);

        fechaArquivo(inp);
        fechaArquivo(out);

    }
    else{
        printf("Número incorreto de parâmetros. Fazer seguir exemplo:\n\n\t./tp1 input.txt output.txt\n\n"); exit(0);
    }
    return 0;
}

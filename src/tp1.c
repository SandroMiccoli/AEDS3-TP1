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
        int k; // Instâncias de matrizes
        int cidade_cen_1,cidade_cen_2,cidade_cen_3;
        float prejuizo;

        Grafo G;

        strcat(entrada,argv[1]);
        strcat(saida,argv[2]);

        FILE * inp = abreArquivoLeitura(entrada);
        FILE * out = abreArquivoEscrita(saida);

        fscanf(inp, "%d ", &k); // Lê as k instâncias de problemas

        for (int l=0; l<k; l++){

            inicializaGrafo(inp, &G);

            dijkstra_all(G);

            cidade_cen_1 = cenarioUm(G);
            cidade_cen_2 = cenarioDois(G);
            cidade_cen_3 = cenarioTres(G);
            prejuizo     = cenarioQuatro(G,cidade_cen_1,cidade_cen_3);

            fprintf(out,"%d ",cidade_cen_1);
            fprintf(out,"%d ",cidade_cen_2);
            fprintf(out,"%d ",cidade_cen_3);
            fprintf(out,"%.2f\n",prejuizo);

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

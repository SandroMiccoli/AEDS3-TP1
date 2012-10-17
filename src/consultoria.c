/*
  Módulo que realiza os cálculos da consultoria para a Atlanticon.

  Criação: 17/10/12
  Autor: Sandro Miccoli


    Deve-se escolher a melhor cidade para os três cenários distintos descritos abaixo,
    para cada um deles deverá ser retornardo um identificador da melhor cidade possível.

    Além disso, deve se retornar um quarto item, também descrito abaixo.

    Cenário 1
        Identificador da cidade na qual a filial deve ser instalada para minimizar o
        gasto em combustível considerando a mesma quantidade de pedidos em cada cidade.


    Cenário 2
        Identificador da cidade na qual a filial deve ser instalada para minimizar o
        gasto em combustível considerando a média de pedidos de cada cidade dada como entrada.


    Cenário 3
        Identificador da cidade na qual a filial deve ser instalada para minimizar o
        valor X do serviço de entrega rápida.

    Identificador 4
        Prejuízo percentual acarretado quando a cidade é escolhida de modo a garantir o menor tempo
        de entrega máximo.


*/



#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INT_MAX
#include "grafos_matriz.h"

#define INF INT_MAX

/*
    Cenário 1
        Identificador da cidade na qual a filial deve ser instalada para minimizar o
        gasto em combustível considerando a mesma quantidade de pedidos em cada cidade.

*/
int cenarioUm(Grafo G){

    int menorGasto=INF; // Variável que representa o menor gasto de combustível
    int gastoAux;

    int cidade; // Variável que representa a cidade que possui o menor gasto de combustível

    for (int i=0; i<G.N; i++){
        gastoAux = 0;

        // Calcula o somatório do gasto de combustível da cidade i
        for (int j=0; j<G.N; j++){
            gastoAux += G.matrizAdj.matriz[i][j];
        }

        // Caso o gasto da cidade i seja o menor gasto
        if (gastoAux < menorGasto){
            menorGasto = gastoAux;
            cidade = i;
        }
    }


    return cidade+1;

}

/*
    Cenário 2
        Identificador da cidade na qual a filial deve ser instalada para minimizar o
        gasto em combustível considerando a média de pedidos de cada cidade dada como entrada.

*/
int cenarioDois(Grafo G){

    int menorGasto=INF; // Variável que representa o menor gasto de combustível
    int gastoAux;

    int cidade; // Variável que representa a cidade que possui o menor gasto de combustível

    for (int i=0; i<G.N; i++){
        gastoAux = 0;

        // Calcula o somatório do gasto de combustível da cidade i de acordo com o volume de pedidos de cada cidade j
        for (int j=0; j<G.N; j++){
            gastoAux += G.matrizAdj.matriz[i][j] * G.Vol[j];
        }

        // Caso o gasto da cidade i seja o menor gasto
        if (gastoAux < menorGasto){
            menorGasto = gastoAux;
            cidade = i;
        }
    }


    return cidade+1;

}

/*
    Cenário 3
        Identificador da cidade na qual a filial deve ser instalada para minimizar o
        valor X do serviço de entrega rápida.

*/
int cenarioTres(Grafo G){

    int maiorDist=INF; // Variável que representa a maior distância
    int distAux;

    int cidade; // Variável que representa a cidade que possui a menor distância dentre as maiores percorridas de todas as cidades

    for (int i=0; i<G.N; i++){
        distAux = 0;

        // Descobre qual a cidade j de maior distância da a cidade i
        for (int j=0; j<G.N; j++){
            if (G.matrizAdj.matriz[i][j] > distAux)
                distAux = G.matrizAdj.matriz[i][j];
        }

        // Armazena a menor dentre as maiores distâncias percorridas de cada cidade
        if (distAux < maiorDist){
            maiorDist = distAux;
            cidade = i;
        }
    }


    return cidade+1;

}
/*
    Identificador 4
        Prejuízo percentual acarretado quando a cidade 3 é escolhida de modo a garantir o menor tempo
        de entrega máximo.
*/
float prejuizoCen3(Grafo G, int cen1, int cen3){
    float prejuizo=0;
    int custoCen1 = 0, custoCen3 = 0;

    // Recupera o custo do cenario 1
    for (int i = 0; i < G.N; i++){
        custoCen1 += G.matrizAdj.matriz[cen1-1][i];
    }

    // Recupera o custo do cenário 3
    for (int i = 0; i < G.N; i++){
        custoCen3 += G.matrizAdj.matriz[cen3-1][i];
    }

    prejuizo = (((float)custoCen3*100.0)/(float)custoCen1) - 100.0;

    return prejuizo;
}

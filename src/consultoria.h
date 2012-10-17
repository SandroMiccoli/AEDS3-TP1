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

    Cenário 4
        Prejuízo percentual acarretado quando a cidade é escolhida de modo a garantir o menor tempo
        de entrega máximo.


*/


#include <stdio.h>
#include <stdlib.h>
#include "grafos_matriz.h"

/*
    Cenário 1
        Identificador da cidade na qual a filial deve ser instalada para minimizar o
        gasto em combustível considerando a mesma quantidade de pedidos em cada cidade.

*/
int cenarioUm(Grafo G);

/*
    Cenário 2
        Identificador da cidade na qual a filial deve ser instalada para minimizar o
        gasto em combustível considerando a média de pedidos de cada cidade dada como entrada.

*/
int cenarioDois(Grafo G);

/*
    Cenário 3
        Identificador da cidade na qual a filial deve ser instalada para minimizar o
        valor X do serviço de entrega rápida.

*/
int cenarioTres(Grafo G);

/*
    Cenário 4
        Prejuízo percentual acarretado quando a cidade é escolhida de modo a garantir o menor tempo
        de entrega máximo.
*/
float cenarioQuatro(Grafo G, int cen1, int cen3);

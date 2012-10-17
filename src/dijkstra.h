/*
  Módulo que contém o algoritmo de Dijkstra.

  Criação: 16/10/12
  Autor: Sandro Miccoli

*/

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

// Calcula o Dijkstra para o vértice v
void dijkstra (Grafo G, int v);

//
// Realiza o Dijkstra para cada vértice do grafo
//
// Transforma a matriz de adjacência do grafo em uma matriz de distãncias de cada cidade
//
void dijkstra_all (Grafo G);

#endif /* DIJKSTRA_H_ */

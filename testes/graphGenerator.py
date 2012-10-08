#!/usr/bin/python
# -*- coding: latin-1 -*-

'''
Gerador de matrizes quadradadas simétricas em relação à diagonal principal.

Para executar: ./graphGenerator.py <n instancias> <dimensão da matriz>

Para salvar num arquivo: <comando acima> > <arquivo de saída>

Exemplo de saída:

1			-> K instâncias
5			-> Dimensão (n cidades)
0 6 8 8 8 
6 0 8 4 3 
8 8 0 9 7 
8 4 9 0 5 
8 3 7 5 0 
963 237 938 796 364 	-> Volume de pedidos


Fonte: http://stackoverflow.com/questions/2572916/numpy-smart-symmetric-matrix


'''

import random
import sys
import numpy

k = int(sys.argv[1]) # instâncias do problema
maxN = int(sys.argv[2]) # tamanho máximo de cidades

class SymNDArray(numpy.ndarray):
    def __setitem__(self, (i, j), value):
        numpy.ndarray.__setitem__(self, (i, j), value)
        numpy.ndarray.__setitem__(self, (j, i), value)

def symarray(input_array):
    "Returns a symmetrized version of input_array; further assignments to the array are automatically symmetrized."
    return symmetrize(numpy.array(input_array)).view(SymNDArray)

def symmetrize(a):
    return a + a.T - numpy.diag(a.diagonal())


print k

for l in range(k):

	print maxN

	matriz = symarray(numpy.zeros((maxN, maxN)))

	# Gera o grafo simétrico.
	for i in range(maxN):
		for j in range(maxN):
			matriz[i,j] = random.randint(0,9)
			if i==j:
				matriz[i,j] = 0
	
	# Imprime o grafo
	for i in range(maxN):
		for j in range(maxN):
			print int(matriz[i][j]),
		print ""

	# Imprime o volume médio de pedidos que cada cidade
	for i in range(maxN):
		print random.randint(0,1000),
	print ""



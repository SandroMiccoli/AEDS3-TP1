#!/usr/bin/python
# -*- coding: latin-1 -*-

import random, os, sys;

arquivo = str(sys.argv[1]) # nome do arquivo a ser usado de input

f = open(arquivo+'.txt')

with f:
	k = [int(x) for x in f.readline().split()]
	n = [int(x) for x in f.readline().split()]
	array = [[int(x) for x in line.split()] for line in f]

init = """
graph G {
	size = "5";
	ratio = "fill";
	layout = fdp;
	K=.5;
	node [shape=circle style=filled fillcolor=lightblue];
"""

try:
	graph = open(arquivo+".dot","w")
	try:
		graph.writelines(init)
		
		i=1
		for linhas in array:
			j=1
			if i < n[0]+1:
				for dist in linhas:
					if (j < i+1 and j!=i and dist>0):
						graph.write("\t"+str(i)+" -- "+str(j)+" [ label = "+str(dist)+" ];\n");
					j+=1
			i+=1

		graph.write("}");
	finally:
		graph.close()
except IOError:
	pass

os.popen("fdp -Tpng "+arquivo+".dot -o "+arquivo+".png").read()


#!/usr/bin/python
# -*- coding: latin-1 -*-

import random, os, sys;



k = int(sys.argv[1]) # instâncias do problema
maxN = int(sys.argv[2]) # tamanho máximo de cidades
sORd = int(sys.argv[3]) # gera grafos esparsos (0) ou densos (1)
arquivo = str(sys.argv[4]) # nome do arquivo a ser usado de input

os.popen("./graphGenerator.py "+str(k)+" "+str(maxN)+" "+str(sORd)+" > "+arquivo+".txt").read()


os.popen("./graphVis.py "+arquivo).read()

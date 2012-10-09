#!/usr/bin/python
# -*- coding: latin-1 -*-

import random, os, sys;



k = int(sys.argv[1]) # instâncias do problema
maxN = int(sys.argv[2]) # tamanho máximo de cidades
arquivo = str(sys.argv[3]) # nome do arquivo a ser usado de input

os.popen("./graphGenerator.py "+str(k)+" "+str(maxN)+" > "+arquivo+".txt").read()


os.popen("./graphVis.py "+arquivo).read()

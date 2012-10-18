#!/usr/bin/python
# -*- coding: latin-1 -*-

# Comando utilizado posteriormente para obter nome do arquivo e apenas o tempo de execução
#
# $ head -1 * | awk -F'user' '{print $1}'

import sys,os,random

ent = 'entrada/'
sai = 'saida/'
tempo = 'tempo/'
script = './grafos/graphGenerator.py '
arqAppend = ' >> '
arqNew = ' > '
tp = ' ./tp1 '

sparse = 0
dense = 1

for i in range(50):
    i+=1
    i*=10
    #teste = script+' 1 '+str(i)+' '+str(sparse)+' ' # Grafos esparsos crescentes
    #teste = script+' 1 '+str(i)+' '+str(dense)+' ' # Grafos densos crescentes
    #teste = script+str(i)+' 25 '+' '+str(sparse)+' ' # Grafos esparsos com instâncias crescentes
    teste = script+str(i)+' 25 '+' '+str(dense)+' ' # Grafos densos com instâncias crescentes

    arqEnt= 'ent'+str(i)+'.txt'
    arqSai= 'sai'+str(i)+'.txt'
    arqTmp= 'tmp'+str(i)+'.txt'

    os.system(teste+arqNew+ent+arqEnt)
    #os.system('./tp0 '+arqEnt+' '+arqSai)
    os.system('/usr/bin/./time -o '+tempo+arqTmp+tp+arqEnt+' '+arqSai)

os.system('ls '+ent)
os.system('ls '+sai)
os.system('ls '+tempo)

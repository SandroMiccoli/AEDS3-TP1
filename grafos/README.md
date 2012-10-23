Gerador de Grafos
=================

Scripts que geram grafos de acordo com a especificação do trabalho prático.

Para executálos é necessário instalar o pacote python-numpy:

	sudo apt-get install python-numpy

Além disso, utilizando a ferramenta graphviz(http://www.graphviz.org/), foi criado um script para gerar um .png do grafo em questão.

Para utilizar os scripts:

Gerador de grafo:

	./grafoGenerator.py <n instâncias> <dimensão dos grafos> <esparso 0 ou denso 1>

	Ex: ./grafoGenerator.py 1 7 0
	Com saída em arquivo: ./grafoGenerator.py 1 7 0 > saida.txt

Gerador de .png:

	./grafoVis.py <nome do arquivo txt SEM EXTENSÃO que contém o grafo>

	Ex: ./grafoVis.py saida

Ou um terceiro script que faz as duas funções, gera o grafo, um arquivo .txt com seu conteúdo e um .png com sua visualização:

	./grafoGeneratorAndVis.py <n instâncias> <dimensão dos grafos> <esparso 0 ou denso 1> <nome do arquivo de saída (irá criar um .txt, .dot e .png)>

	Ex: ./grafoGeneratorAndVis.py 1 6 0 saida

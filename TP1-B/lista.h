#pragma once
#include <iostream>

struct NoL 
{
	int valor;
	NoL* dir;
	NoL* esq;
};

class lista
{
private:
	NoL* sentinela;

	//Tamanho da lista
	int cardinalidade_;

	//Para o laboratório poder acessar os frascos diretamente.
	friend class laboratorio;

public:
	//Cria uma lista vazia
	lista();

	//Adiciona elemento à lista
	void addElement(int volume);

	//Deleta o elemento de valor "volume"
	void deleteElement(int volume);

	//Printa a lista
	void printL();

	//Destrutor da lista
	~lista();
};


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
protected:
	NoL* sentinela;
	int cardinalidade_;
	friend class laboratorio;

public:
	//Cria uma lista vazia
	lista();

	//Adiciona elemento � lista
	void addElement(int volume);

	//Deleta o elemento de valor "volume"
	void deleteElement(int volume);

	//Printa a lista
	void printL();

	//Destrutor da lista
	~lista();
};


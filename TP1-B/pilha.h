#pragma once

struct NoP {
	int valor;
	NoP* dir;
	NoP* esq;
};

class pilha
{
private:
	NoP* sentinela;
	int operacoes_;
	int cardinalidade_;

public:
	//Cria uma pilha vazia
	pilha(int oper);

	//Adiciona elemento à lista
	void Empilha(int volume);

	//Desempilha o elemento
	int Desempilha();

	//Destrutor da pilha
	~pilha();
};


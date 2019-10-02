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

	//Quantidade de operações que essa pilha representa
	int operacoes_;

	//Tamanho da pilha
	int cardinalidade_;

public:
	//Cria uma pilha vazia
	pilha(int oper);

	//Adiciona elemento à lista
	void Empilha(int volume);

	//Desempilha o elemento
	int Desempilha();

	//Retorna o numero de operações
	int operacoes();

	//Retorna o tamanho da pilha
	int size();

	//Destrutor da pilha
	~pilha();
};


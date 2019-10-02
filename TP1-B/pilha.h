#ifndef PILHA_H
#define PILHA_H

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

	//Retorna o numero de operações
	int operacoes();

	//Retorna o tamanho da pilha
	int size();

	//Destrutor da pilha
	~pilha();
};

#endif //PILHA_H
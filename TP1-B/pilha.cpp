#include "pilha.h"

pilha::pilha(int oper)
{
	sentinela = new NoP;
	cardinalidade_ = 0;
	sentinela->valor = 0;
	sentinela->dir = sentinela;
	sentinela->esq = sentinela;
	operacoes_ = oper;
}

void pilha::Empilha(int volume)
{
	NoP* novo = new NoP;
	novo->valor = volume;
	novo->esq = sentinela;
	novo->dir = sentinela->dir;
	sentinela->dir->esq = novo;
	sentinela->dir = novo;
	if (cardinalidade_ == 0) {
		sentinela->esq = novo;
	}
	cardinalidade_++;
}

int pilha::Desempilha()
{
	if(cardinalidade_ > 0){
		NoP* primeiro = sentinela->dir;
		int vol = primeiro->valor;
		sentinela->dir = sentinela->dir->dir;
		sentinela->dir->esq = sentinela;
		delete primeiro;
		cardinalidade_--;
		return vol;
	}
	else {
		return -1000;
	}
}

int pilha::operacoes()
{
	return operacoes_;
}


pilha::~pilha()
{
	int valor = Desempilha();
	while (valor >= 0) {
		valor = Desempilha();
	}
}

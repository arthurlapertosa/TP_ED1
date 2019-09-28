#include "lista.h"

lista::lista()
{
	sentinela = new NoL;
	cardinalidade_ = 0;
	sentinela->valor = 0;
	sentinela->dir = sentinela;
	sentinela->esq = sentinela;

}

void lista::addElement(int volume)
{
	NoL* novo = new NoL;
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

void lista::deleteElement(int volume)
{
	NoL* i;
	for (i = sentinela->dir; i != sentinela; i = i->dir) {
		if (i->valor == volume) {
			NoL* ElementEsq = i->esq;
			ElementEsq->dir = ElementEsq->dir->dir;
			ElementEsq->dir->esq = ElementEsq;
			delete i;
			cardinalidade_--;
			break;
		}
	}
}

void lista::printL()
{
	NoL* i;
	for (i = sentinela->esq; i != sentinela; i = i->esq) {
		std::cout << i->valor << "ml -> ";
	}
	std::cout << std::endl;
}

lista::~lista()
{
	NoL* i = sentinela->dir;
	NoL* iProx;
	while (i != sentinela) {
		iProx = i->dir;
		deleteElement(i->valor);
		i = iProx;
	}
}

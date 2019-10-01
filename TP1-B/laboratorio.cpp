#include "laboratorio.h"

laboratorio::laboratorio()
{
}

laboratorio::laboratorio(int volume)
{
	adicionarFrasco(volume);
}

void laboratorio::adicionarFrasco(int volume)
{
	frascos.addElement(volume);
}

void laboratorio::removerFrasco(int volume)
{
	frascos.deleteElement(volume);
}

void laboratorio::PrintFrascos()
{
	frascos.printL();
}

int laboratorio::buscaOperacoes(int volume)
{
	NoL* i;
	//pilha* aux = new pilha(1);
	std::stack<int>* aux = new std::stack<int>;
	for (i = frascos.sentinela->esq; i != frascos.sentinela; i = i->esq) {
		//std::cout << i->valor << "ml -> ";
		if (i->valor == volume) {
			return 1;
		}
		aux->emplace(i->valor);
	}

	int indexLoop = 2;
	//pilha* anterior;
	std::stack<int>* anterior;
	anterior = aux;

	while (1) {
		//pilha* loop = new pilha(indexLoop);
		std::stack<int>* loop = new std::stack<int>;

		
		
		while(anterior->size() > 0){
			int valor = anterior->top();
			NoL* j;
			for (j = frascos.sentinela->esq; j != frascos.sentinela; j = j->esq) {
				loop->emplace(valor + j->valor); //Empilha o novo valor
				if (valor - j->valor > 0) { //Testa se o valor a ser empilhado é positivo
					loop->emplace(valor - j->valor); //Empilha o novo valor
				}
				if ((valor + j->valor == volume) || (valor - j->valor == volume) ) {
					return indexLoop; //Se o valor for encontrado, retorna ele.
				}
			}
			anterior->pop();
		}
		std::cout << "Operacao numero: " << indexLoop << std::endl;
		anterior = loop;
		std::cout << "Tamanho da pilha atual: " << anterior->size() << std::endl;
		indexLoop++;
	}
}

void laboratorio::interpretador(char* str)
{
	int volume;
	char operacao;
	if(sscanf(str, "%d %c", &volume, &operacao) == 2){
		if (operacao == 'i') {
			adicionarFrasco(volume);
		}
		else if (operacao == 'r') {
			removerFrasco(volume);
		}
		else if (operacao == 'p') {
			std::cout << "                        " << buscaOperacoes(volume) << std::endl;
		}
		else {
			std::cout << "Formato inválido" << std::endl;
		}
	}
	else {
		std::cout << "Formato inválido" << std::endl;
	}
}

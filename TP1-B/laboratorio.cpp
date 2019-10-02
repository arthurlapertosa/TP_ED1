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
	//se o volume desejado é 0ml, então é necessário 0 operação
	if (volume == 0) {
		return 0;
	}
	NoL* i;
	pilha* aux = new pilha(1);
	for (i = frascos.sentinela->esq; i != frascos.sentinela; i = i->esq) {
		//std::cout << i->valor << "ml -> ";
		if (i->valor == volume) {
			return 1;
		}
		aux->Empilha(i->valor);
	}

	int indexLoop = 2;
	pilha* anterior;
	anterior = aux;

	while (1) {
		pilha* loop = new pilha(indexLoop);

		int valor = anterior->Desempilha();

		while(valor >= 0){
			NoL* j;
			for (j = frascos.sentinela->esq; j != frascos.sentinela; j = j->esq) {
				loop->Empilha(valor + j->valor); //Empilha o novo valor
				if (valor - j->valor > 0) { //Testa se o valor a ser empilhado é positivo
					loop->Empilha(valor - j->valor); //Empilha o novo valor
				}
				if ((valor + j->valor == volume) || (valor - j->valor == volume) ) {
					return loop->operacoes(); //Se o valor for encontrado, retorna ele.
				}
			}
			valor = anterior->Desempilha();
		}

		anterior = loop;
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

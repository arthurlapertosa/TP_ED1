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
	pilha* aux = new pilha(1);
	//Monta a primeira pilha, equivalente a uma opera��o
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
		//Pilha da itera��o atual
		pilha* loop = new pilha(indexLoop);

		int valor = anterior->Desempilha();
		std::cout <<  "Operacao de numero:  " << indexLoop << std::endl;
		while(valor >= 0){ //Se o valor for menor do que 0, na minha implementa��o, significa que a pilha est� vazia (uma vez que a nossa pilha n�o recebe valores negativos, resolvi fazer desse jeito)
			NoL* j;
			//Itera sobre os frascos
			for (j = frascos.sentinela->esq; j != frascos.sentinela; j = j->esq) {
				loop->Empilha(valor + j->valor); //Empilha o novo valor
				if (valor - j->valor > 0) { //Testa se o valor a ser empilhado � positivo
					loop->Empilha(valor - j->valor); //Empilha o novo valor
				}
				//std::cout << valor + j->valor << std::endl << valor - j->valor << std::endl;
				if ((valor + j->valor == volume) || (valor - j->valor == volume) ) {
					return loop->operacoes(); //Se o valor for encontrado, retorna ele.
				}
			}
			valor = anterior->Desempilha();
		}
		std::cout << "Tamanho da pilha: " << loop->size() << std::endl;
		std::cout << std::endl;

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
			std::cout << "Formato inv�lido" << std::endl;
		}
	}
	else {
		std::cout << "Formato inv�lido" << std::endl;
	}
}

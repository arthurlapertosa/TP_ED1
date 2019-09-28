#include "lista.h"
#include "pilha.h"
#include "laboratorio.h"

int main() {
	//lista a;
	//for (int i = 0; i < 100; i++) {
	//	a.addElement(i);
	//}
	//a.printL();

	//std::cout << std::endl;

	//a.deleteElement(10);
	//a.printL();
	//pilha *b = new pilha(0);
	//for (int i = 0; i < 100; i++) {
	//	b->Empilha(i);
	//}
	//int valor = b->Desempilha();
	//
	//while(valor >= 50){
	//	std::cout << valor << std::endl;
	//	valor = b->Desempilha();
	//}
	laboratorio Fini(50);
	Fini.adicionarFrasco(70);
	Fini.adicionarFrasco(120);
	Fini.PrintFrascos();
	std::cout << std::endl;
	Fini.removerFrasco(70);
	Fini.removerFrasco(60);
	Fini.PrintFrascos();

}
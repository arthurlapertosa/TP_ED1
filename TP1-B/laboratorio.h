#pragma once
#include "lista.h"
#include "pilha.h"

class laboratorio
{
private:
	lista frascos;

public:
	//Cria um laboratório sem frascos
	laboratorio();

	//Cria um laboratorio ja com um frasco
	laboratorio(int volume);

	//Adiciona um frasco novo
	void adicionarFrasco(int volume);

	//Remove um frasco
	void removerFrasco(int volume);

	//Printa os frascos atuais
	void PrintFrascos();

	int buscaOperacoes();
};


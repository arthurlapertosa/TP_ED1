#define _CRT_SECURE_NO_WARNINGS // Para o compilador deixar usar funções de C no C++ tive que adicionar isso
#pragma once
#include "lista.h"
#include "pilha.h"
#include <stdio.h>


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

	//Faz o cálculo do número de operações necessárias para se obter o "volume"
	int buscaOperacoes(int volume);

	//Interpretador de strings de acordo com o desejado
	void interpretador(char *str);
};


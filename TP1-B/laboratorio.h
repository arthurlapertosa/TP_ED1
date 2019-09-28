#define _CRT_SECURE_NO_WARNINGS // Para o compilador deixar usar fun��es de C no C++ tive que adicionar isso
#pragma once
#include "lista.h"
#include "pilha.h"
#include <stdio.h>


class laboratorio
{
private:
	lista frascos;

public:
	//Cria um laborat�rio sem frascos
	laboratorio();

	//Cria um laboratorio ja com um frasco
	laboratorio(int volume);

	//Adiciona um frasco novo
	void adicionarFrasco(int volume);

	//Remove um frasco
	void removerFrasco(int volume);

	//Printa os frascos atuais
	void PrintFrascos();

	//Faz o c�lculo do n�mero de opera��es necess�rias para se obter o "volume"
	int buscaOperacoes(int volume);

	//Interpretador de strings de acordo com o desejado
	void interpretador(char *str);
};


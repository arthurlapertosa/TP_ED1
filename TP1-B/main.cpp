#include "laboratorio.h"

int main() {
	laboratorio Fini;
	char str[500] = "\0";
	char dump;
	while (1) {
		str[0] = '\0';
		fgets(str, 500, stdin);
		if (str[0] == '\0') {
			//Sai do programa se o usuário digitou CNTRL + Z no windows
			break;
		}
		//Chama a função que interpreta o que o usuário digitou
		Fini.interpretador(str);
	}
}
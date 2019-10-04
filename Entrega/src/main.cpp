#include "laboratorio.h"

int main() {
	laboratorio Fini;
	char str[500] = "\0";
	while (1) {
		str[0] = '\0';
		fgets(str, 500, stdin);
		if (str[0] == '\0') {
			//Sai do programa se o usu�rio digitou CNTRL + Z no windows
			break;
		}
		//Chama a fun��o que interpreta o que o usu�rio digitou
		Fini.interpretador(str);
	}
}
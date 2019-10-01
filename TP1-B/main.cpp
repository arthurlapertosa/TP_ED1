#include "laboratorio.h"

int main() {
	laboratorio Fini;
	char str[500000];
	char dump;
	while (1) {
		scanf("%[^\n]", str);
		scanf("%c", &dump);
		Fini.interpretador(str);
	}
}
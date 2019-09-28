#include "lista.h"

int main() {
	lista a;
	for (int i = 0; i < 100; i++) {
		a.addElement(i);
	}
	a.printL();

	std::cout << std::endl;

	a.deleteElement(10);
	a.printL();
}
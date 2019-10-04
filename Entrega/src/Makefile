CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp1 # nome do executavel que sera gerado, nao troque
TMPOUT=tp1.testresult

$(EXEC): main.cpp pilha.o lista.o laboratorio.o
	$(CC) $(CFLAGS) main.cpp pilha.o lista.o laboratorio.o -o $(EXEC)

pilha.o: pilha.cpp
	$(CC) $(CFLAGS) -c pilha.cpp -o pilha.o

lista.o: lista.cpp
	$(CC) $(CFLAGS) -c lista.cpp -o lista.o

laboratorio.o: laboratorio.cpp
	$(CC) $(CFLAGS) -c laboratorio.cpp -o laboratorio.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf pilha.o
	rm -rf lista.o
	rm -rf laboratorio.o


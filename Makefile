CC = g++

CFLAGS = -Wall -O2 -I./include -std=c++11

all: main tests_unitaire

main: main.o Arete.o Graphe_colore.o Graphe_solveur.o Sudoku.o
	$(CC) $(CFLAGS) -o bin/main obj/main.o obj/Arete.o obj/Graphe_colore.o obj/Graphe_solveur.o obj/Sudoku.o

tests_unitaire: tests_unitaire.o Arete.o Graphe_colore.o Graphe_solveur.o Sudoku.o
	$(CC) $(CFLAGS) -o bin/tests_unitaire obj/tests_unitaire.o obj/Arete.o obj/Graphe_colore.o obj/Graphe_solveur.o obj/Sudoku.o

main.o: main.cpp include/Arete.hpp include/Graphe_colore.hpp include/Graphe_solveur.hpp include/Sudoku.hpp
	$(CC) $(CFLAGS) -c main.cpp -o obj/main.o

tests_unitaire.o: tests_unitaire.cpp include/Arete.hpp include/Graphe_colore.hpp include/Graphe_solveur.hpp include/Sudoku.hpp
	$(CC) $(CFLAGS) -c tests_unitaire.cpp -o obj/tests_unitaire.o

Arete.o: src/Arete.cpp include/Arete.hpp
	$(CC) $(CFLAGS) -c src/Arete.cpp -o obj/Arete.o

Graphe_colore.o: src/Graphe_colore.cpp include/Graphe_colore.hpp
	$(CC) $(CFLAGS) -c src/Graphe_colore.cpp -o obj/Graphe_colore.o

Graphe_solveur.o: src/Graphe_solveur.cpp include/Graphe_solveur.hpp
	$(CC) $(CFLAGS) -c src/Graphe_solveur.cpp -o obj/Graphe_solveur.o

Sudoku.o: src/Sudoku.cpp include/Sudoku.hpp
	$(CC) $(CFLAGS) -c src/Sudoku.cpp -o obj/Sudoku.o

clean:
	rm -f bin/main bin/tests_unitaire obj/tests_unitaire.o obj/Arete.o obj/Graphe_colore.o obj/Graphe_solveur.o obj/Sudoku.o obj/main.o obj/tests_unitaire.o

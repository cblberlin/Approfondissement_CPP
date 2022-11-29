CXXFLAGS = -Wall -g

PROGS = tests_unitaire

all: $(PROGS)

tests_unitaire: tests_unitaire.o Arete.o Graphe_colore.o Graphe_solveur.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

tests_unitaire.o: tests_unitaire.cpp Arete.hpp  Graphe_colore.hpp Graphe_solveur.hpp
	$(CXX) -c $< $(CXXFLAGS) $(LDFLAGS)


clean:
	-rm -f *.o *~ $(PROGS)


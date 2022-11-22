PROGS = exceptions typage relance relance_corr fonction exception_STL

all : $(PROGS)

exceptions: exceptions.cpp
	g++ -o $@ $^

typage: typage.cpp
	g++ -o $@ $^

relance: relance.cpp
	g++ -o $@ $^

relance_corr: relance_corr.cpp
	g++ -o $@ $^

fonction: fonction.cpp
	g++ -o $@ $^

exception_STL: exception_STL.cpp
	g++ -o $@ $^

clean:
	rm -f *.txt $(PROGS)

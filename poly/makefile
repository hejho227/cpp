headers = Poly.h

sources = poly.cpp testPoly.cpp


executable = testComplex

$(executable): $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)
	
.PHONNY: clean

clean:
	rm $(executable)
	
.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$executable)

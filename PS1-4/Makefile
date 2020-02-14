CXXFLAGS = -Wall -std=c++14

all : convert test

convert: units.o convert.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

test: units.o testbase.o hw3testunits.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

doc: Doxyfile
	doxygen

clean:
	rm -f convert hw3testunits docs *.o *~

.PHONY: all doc clean

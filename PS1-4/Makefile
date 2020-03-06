CXXFLAGS = -Wall -Werror -Wpedantic -Werror=sign-compare -std=c++14

all : convert hw3testunits

convert: units.o convert.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

hw3testunits: units.o testbase.o hw3testunits.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

test: hw3testunits
	./hw3testunits

doc:
	doxygen

clean:
	rm -rf convert hw3testunits docs *.o *~

.PHONY: all test doc clean

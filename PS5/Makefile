CXXFLAGS = -Wall -Werror -std=c++14

all : test-rational

test: test-rational
	./test-rational

test-rational: rational.o testbase.o test-rational.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf test-rational *.o *~

.PHONY: all clean

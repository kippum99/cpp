CXXFLAGS = -Wall -Werror -std=c++14

all : rational.o testbase.o test-rational.o
	$(CXX) $(CXXFLAGS) $^ -o test-rational $(LDFLAGS)

test: test-rational
	./test-rational

clean:
	rm -rf test-rational *.o *~

.PHONY: all clean

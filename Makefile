CXX := g++
OBJ := lin-algebra.o
TEST_OBJ := test.o test-linalg.o

.PHONY: all test clean

all: lin-algebra

lin-algebra: $(OBJ) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test-runner: $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lcppunit

test: test-runner
	./test-runner

clean:
	rm -f *.o lin-algebra test-runner

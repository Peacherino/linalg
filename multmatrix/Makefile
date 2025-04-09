CXX=g++
OBJ=lin-algebra.o
TEST_OBJ=test.o test-linalg.o


main: $(OBJ) main.o
	$(CXX) -o lin-algebra $(OBJ) main.o

test: $(OBJ) $(TEST_OBJ)
	$(CXX) -o test $(OBJ) $(TEST_OBJ) -lcppunit
	./test

all: main test

clean:
	rm *.o test lin-algebra

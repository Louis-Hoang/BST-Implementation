all: test usecase

usecase: main.cpp
	g++ -std=c++11 main.cpp -o usecase

test: test_bst.cpp
	g++ -std=c++11 test_bst.cpp -o test

clean:
	rm -rf *.o test usecase
SHELL=bash
GCC=g++ -std=c++11 -Wall -Wextra -Werror -Wno-sign-compare -O2 -Wno-deprecated

.PHONY: tree, dag

tree.o: libs.h Matrix.h Tree.h isomorphism.h  Matrix.cc Tree.cc isomorphism.cc main.cc
	$(GCC)  Matrix.cc  Tree.cc isomorphism.cc main.cc -o tree.o

tree: tree.o
	./tree.o

dag.o: libs.h Matrix.h Tree.h isomorphism.h dag.h Matrix.cc Tree.cc isomorphism.cc dag.cc main.cc
	$(GCC)  Matrix.cc  Tree.cc isomorphism.cc dag.cc main.cc -o dag.o

dag: dag.o
	./dag.o

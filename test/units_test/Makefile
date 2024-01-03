test_FactList: test_FactList.o FactList.o test_include.o Properties.o
	ggc -o test_FactList test_FactList.o FactList.o Fact.o

test_FactList.o: test_FactList.c
	gcc -o test_FactList.o -c test_FactList.c
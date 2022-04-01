jaguar: jaguar.c bfs.c bfs.h tlw.c tlw.h graf.c graf.h
	gcc -o jaguar jaguar.c bfs.c bfs.h tlw.c tlw.h graf.c graf.h
testbfs: testbfs.c bfs.c bfs.h graf.c graf.h
	gcc -o testbfs testbfs.c bfs.c bfs.h graf.c graf.h
testtlw: testtlw.c tlw.c tlw.h graf.c graf.h
	gcc -o testtlw testtlw.c tlw.c tlw.h graf.c graf.h

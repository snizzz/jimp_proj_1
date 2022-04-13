jaguar: src/jaguar.c src/bfs.c headers/bfs.h src/tlw.c headers/tlw.h src/dijkstra.c headers/dijkstra.h src/graf.c headers/graf.h src/backtracker.c headers/backtracker.h headers/bruteforce.h src/bruteforce.c src/stack.c headers/stack.h src/prioque.c headers/prioque.h
	gcc -o jaguar src/jaguar.c src/bfs.c headers/bfs.h src/tlw.c headers/tlw.h src/dijkstra.c headers/dijkstra.h src/graf.c headers/graf.h src/backtracker.c headers/backtracker.h headers/bruteforce.h src/bruteforce.c src/stack.c headers/stack.h src/prioque.c headers/prioque.h

testbfs: testy/testbfs.c src/bfs.c  headers/bfs.h src/graf.c  headers/graf.h
	gcc -o testbfs testy/testbfs.c src/bfs.c  headers/bfs.h src/graf.c  headers/graf.h

testtlw: testy/testtlw.c src/tlw.c headers/tlw.h src/graf.c headers/graf.h
	gcc -o testtllw testy/testtlw.c src/tlw.c headers/tlw.h src/graf.c headers/graf.h

testgraf: testy/testgraf.c src/graf.c headers/graf.h
	gcc -o testgraf testy/testgraf.c src/graf.c headers/graf.h

testbt: testy/testBt.c src/graf.c headers/graf.h src/stack.c headers/stack.h src/bfs.c headers/bfs.h src/backtracker.c headers/backtracker.h
	gcc -o testbt testy/testBt.c src/graf.c headers/graf.h src/stack.c headers/stack.h src/bfs.c headers/bfs.h src/backtracker.c headers/backtracker.h

testdijkstra: testy/testdijkstra.c src/graf.c headers/graf.h src/prioque.c headers/prioque.h src/dijkstra.c headers/dijkstra.h
	gcc -o testdijkstra  testy/testdijkstra.c src/graf.c headers/graf.h src/prioque.c headers/prioque.h src/dijkstra.c headers/dijkstra.h

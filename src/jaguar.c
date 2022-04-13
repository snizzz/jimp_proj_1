#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "../headers/graf.h"
#include "../headers/bfs.h"
#include "../headers/tlw.h"
#include "../headers/stack.h"
#include "../headers/prioque.h"
#include "../headers/bruteforce.h"
#include "../headers/backtracker.h"
#include "../headers/djkstra.h"

int main(int argc, char** argv) {
	int mode = 0; // 1 dla trybu mode in, 2 dla trybu mode out
	struct Graph* graph = NULL;
	FILE* in, * out;
	if (argc == 1) {
		printf("***MANUAL***\n");
		printf("graf interprator and analizator Jaguar\n");
		printf("usage: ./jaguar [--help][--mode][--s][--tlw][--tl][--sbt]\n");
		printf("                [--if_connected][--distance]]\n\n");
		printf("\n--help\n@pomoc\n");
		printf("\n--mode [in/out] [nazwa_plik]\n@tworznei lub wczytywanie graf\n");
		printf("\n--s [liczba wierszy] [liczba kolumn] [pocz_wag] [koniec_wag]\n@genracja grafu spojnego\n");
		printf("\n--tlw [liczba wierszy] [liczba kolumn] [pocz_wag] [koniec_wag]\n@generacja grafu z kazdym połaczeniem\n");
		printf("\n--tl [liczba wierszy] [liczba kolumn] [pocz_wag] [koniec_wag]\n@generacja losowego grafu\n");
		printf("\n--sbt [liczba wierszy] [liczba kolumn] [pocz_wag] [koniec_wag]\n@generacja spojnego grafu\n");
		printf("\n--if_connected\n@sprawdzanie czy graf jest spojny\n");
		printf("\n--distance [wierz_start] [wierz_koniec] [w(jezeli wynik z wagami)]\n@odleglosc pomiedzy wierzcholkami\n");
	}
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "--help") == 0) {
			printf("***MANUAL***\n");
			printf("graf interprator and analizator Jaguar\n");
			printf("usage: ./jaguar [--help][--mode][--s][--tlw][--tl][--sbt]\n");
			printf("                [--if_connected][--distance]]\n\n");
			printf("\n--help\n@pomoc\n");
			printf("\n--mode [in/out] [nazwa_plik]\n@tworznei lub wczytywanie graf\n");
			printf("\n--s [liczba wierszy] [liczba kolumn] [pocz_wag] [koniec_wag]\n@genracja grafu spojnego\n");
			printf("\n--tlw [liczba wierszy] [liczba kolumn] [pocz_wag] [koniec_wag]\n@generacja grafu z kazdym połaczeniem\n");
			printf("\n--tl [liczba wierszy] [liczba kolumn] [pocz_wag] [koniec_wag]\n@generacja losowego grafu\n");
			printf("\n--sbt [liczba wierszy] [liczba kolumn] [pocz_wag] [koniec_wag]\n@generacja spojnego grafu\n");
			printf("\n--if_connected\n@sprawdzanie czy graf jest spojny\n");
			printf("\n--distance [wierz_start] [wierz_koniec] [w(jezeli wynik z wagami)]\n@odleglosc pomiedzy wierzcholkami\n");
			return 0;
		}
	}
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "--mode") == 0) {
			if (strcmp(argv[i + 1], "in") == 0) {
				mode = 1;
				if (argv[i + 2][0] != '-') {
					in = fopen(argv[i + 2], "r");
					if (in == NULL) {
						fprintf(stderr, "BŁĄD 3: nie odnaleziono pliku %s\n", argv[i + 2]);
						return EXIT_FAILURE;
					}
					graph = readGraph(in);
				}
			}
			else if (strcmp(argv[i + 1], "out") == 0) {
				if (argv[i + 2][0] != '-') {
					out = fopen(argv[i + 2], "w+");
					mode = 2;
				}
				else {
					mode = 2;
					out = fopen("out", "w+");
				}
			}
			else if (argv[i + 1][0] != '-') fprintf(stderr, "BŁĄD 2: Podano nieprawidlowy argument %s do flagi --mode\n", argv[i + 1]);
		}
	}
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--if_connected") == 0 && mode == 1) {
			if (ifConnected(graph)) fprintf(stdout, "Connected graph: yes\n");
			else fprintf(stdout, "Connected graph: no\n");
		}
	}
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--tlw") == 0 && mode == 2) {
			int a, b, c = 0, d = 1;
			if (argv[i + 1][0] != '-') {
				a = atoi(argv[i + 1]);
				if (argv[i + 2][0] != '-') {
					b = atoi(argv[i + 2]);
					if (argv[i + 3][0] != '-') {
						c = atoi(argv[i + 3]);
						if (argv[i + 4][0] != '-') {
							d = atoi(argv[i + 4]);
						}
					}
				}

			}
			graph = generateTlw(a, b, c, d);
			writeGraph(graph, out);
		}
		else if (strcmp(argv[i], "--tlw") == 0 && mode == 1) {
			fprintf(stderr, "BŁĄD 1: uzyto niewlasciwej flagi --tlw do podanego trybu\n");
		}
	}
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--sbt") == 0 && mode == 2) {
			int a, b, c = 0, d = 1;
			if (argv[i + 1][0] != '-') {
				a = atoi(argv[i + 1]);
				if (argv[i + 2][0] != '-') {
					b = atoi(argv[i + 2]);
					if (argv[i + 3][0] != '-') {
						c = atoi(argv[i + 3]);
						if (argv[i + 4][0] != '-') {
							d = atoi(argv[i + 4]);
						}
					}
				}
			}
			graph = generateBt(a, b, c, d);
			writeGraph(graph, out);
			free(graph->array);
			free(graph);
			graph = readGraph(out);
		}
		else if (strcmp(argv[i], "--sbt") == 0 && mode == 1) {
			fprintf(stderr, "BŁĄD 1: użyto niewłaściwej flagi --sbt do podanego trybu\n");
		}

	}
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--tl") == 0 && mode == 2) {
			int a, b, c = 0, d = 1;
			if (argv[i + 1][0] != '-') {
				a = atoi(argv[i + 1]);
				if (argv[i + 2][0] != '-') {
					b = atoi(argv[i + 2]);
					if (argv[i + 3][0] != '-') {
						c = atoi(argv[i + 3]);
						if (argv[i + 4][0] != '-') {
							d = atoi(argv[i + 4]);
						}
					}
				}
			}
			graph = generateBf(a, b, c, d);
			writeGraph(graph, out);
		}
		else if (strcmp(argv[i], "--s") == 0 && mode == 1) {
			fprintf(stderr, "BŁĄD 1: użyto niewłaściwej flagi --s do podanego trybu\n");
		}
	}
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--s") == 0 && mode == 2) {
			int a, b, c = 0, d = 1;
			if (argv[i + 1][0] != '-') {
				a = atoi(argv[i + 1]);
				if (argv[i + 2][0] != '-') {
					b = atoi(argv[i + 2]);
					if (argv[i + 3][0] != '-') {
						c = atoi(argv[i + 3]);
						if (argv[i + 4][0] != '-') {
							d = atoi(argv[i + 4]);
						}
					}
				}
			}
			int n = 0;
			do {
				n++;
				if (n > INT_MAX) {
					fprintf(stderr, "Error: Zbyt wiele prob\nNIE UDALO SIE WYLOSOWAC\n");
				}
				graph = generateBf(a, b, c, d);
			} while (ifConnected(graph) != true);
			writeGraph(graph, out);
			printf(">>>>Uddalo sie wylosowac graf spojny po: %d probach<<<<<\n", n);
		}
		else if (strcmp(argv[i], "--s") == 0 && mode == 1) {
			fprintf(stderr, "BŁĄD 1: użyto niewłaściwej flagi --s do podanego trybu\n");
		}
	}
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--distance") == 0 && mode == 1) {
			int a = 0, b = (graph->k * graph->w) - 1;
			char* tryb;
			if (argv[i + 1][0] != '-') {
				a = atoi(argv[i + 1]);
				if (argv[i + 2][0] != '-') {
					b = atoi(argv[i + 2]);
					if (strcmp(argv[i + 3], "-w") == 0) {
						dijkstra(graph, a, b, 'w');
					}
					else {
						dijkstra(graph, a, b, 'd');
					}
				}
			}
		}
	}

	free(graph->array);
	free(graph);
	return 0;
}

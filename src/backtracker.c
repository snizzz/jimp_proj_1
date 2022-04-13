#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/graf.h"
#include "../headers/backtracker.h"
#include "../headers/stack.h"
#define CHANCE 0.5

double diceroll() {
	double ret = (double)(rand()) / (double)(RAND_MAX);
	return ret;
}

struct Graph* generateBt(int m, int n, double w1, double w2) {

	Vertex* vertex = malloc(((n) * (m)) * sizeof * vertex);

	srand(time(NULL));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			vertex[i * n + j].visited = 0;
			if ((i - 1 < 0 || i + 1 >= m) && (j - 1 < 0 || j + 1 >= n)) {
				vertex[i * n + j].direction_count = 2;
				if (i - 1 < 0 && j - 1 < 0) {
					vertex[i * n + j].path_n = 0;
					vertex[i * n + j].path_w = 0;
					vertex[i * n + j].path_s = 1;
					vertex[i * n + j].path_e = 1;
				}
				else if (i + 1 >= m && j - 1 < 0) {
					vertex[i * n + j].path_n = 1;
					vertex[i * n + j].path_w = 0;
					vertex[i * n + j].path_s = 0;
					vertex[i * n + j].path_e = 1;
				}
				else if (i - 1 < 0 && j + 1 >= n) {
					vertex[i * n + j].path_n = 0;
					vertex[i * n + j].path_w = 1;
					vertex[i * n + j].path_s = 1;
					vertex[i * n + j].path_e = 0;
				}
				else if (i + 1 >= m && j + 1 >= n) {
					vertex[i * n + j].path_n = 1;
					vertex[i * n + j].path_w = 1;
					vertex[i * n + j].path_s = 0;
					vertex[i * n + j].path_e = 0;
				}
			}
			else if (i - 1 < 0 || j - 1 < 0 || i + 1 >= m || j + 1 >= n) {
				vertex[i * n + j].direction_count = 3;
				if (i - 1 < 0) {
					vertex[i * n + j].path_n = 0;
					vertex[i * n + j].path_w = 1;
					vertex[i * n + j].path_s = 1;
					vertex[i * n + j].path_e = 1;
				}
				if (i + 1 >= m) {
					vertex[i * n + j].path_n = 1;
					vertex[i * n + j].path_w = 1;
					vertex[i * n + j].path_s = 0;
					vertex[i * n + j].path_e = 1;
				}
				if (j - 1 < 0) {
					vertex[i * n + j].path_n = 1;
					vertex[i * n + j].path_w = 0;
					vertex[i * n + j].path_s = 1;
					vertex[i * n + j].path_e = 1;
				}
				if (j + 1 >= n) {
					vertex[i * n + j].path_n = 1;
					vertex[i * n + j].path_w = 1;
					vertex[i * n + j].path_s = 1;
					vertex[i * n + j].path_e = 0;
				}
			}
			else {
				printf("c\n");
				vertex[i * n + j].direction_count = 4;
				vertex[i * n + j].path_n = 1;
				vertex[i * n + j].path_w = 1;
				vertex[i * n + j].path_s = 1;
				vertex[i * n + j].path_e = 1;
			}
		}
	}


	int k = 1;
	int x = 0, y = 0;
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph = makeGraph(m, n);
	struct Stack* root = createStack(n * m);
	while (1 == 1) {
		if (vertex[y * n + x].direction_count == 0) printf("hi\n");
		double direction = vertex[y * n + x].direction_count * (double)rand() / (double)RAND_MAX;
		int nt = 0;
		int w = 0;
		int s = 0;
		int e = 0;
		if (vertex[y * n + x].path_n == 1) {
			nt = k;
			k++;
		}
		if (vertex[y * n + x].path_w == 1) {
			w = k;
			k++;
		}
		if (vertex[y * n + x].path_s == 1) {
			s = k;
			k++;
		}
		if (vertex[y * n + x].path_e == 1) {
			e = k;
			k++;
		}

		int g = y * n + x;

		if (vertex[y * n + x].path_n == 1 && direction <= nt && vertex[(y - 1) * n + x].visited == 0) {
			double roll = diceroll();
			if (roll < CHANCE) {
				addToGraph(graph, y * n + x, (y - 1) * n + x, w1 + (w2 - w1) * diceroll());
			}
			else {
				addToGraph(graph, y * n + x, (y - 1) * n + x, w1 + (w2 - w1) * diceroll());
				addToGraph(graph, (y - 1) * n + x, y * n + x, w1 + (w2 - w1) * diceroll());
			}
			vertex[y * n + x].path_n = 0;
			--vertex[y * n + x].direction_count;
			vertex[y * n + x].visited = 1;
			vertex[(y - 1) * n + x].path_s = 0;
			--vertex[(y - 1) * n + x].direction_count;
			if (vertex[(y + 1) * n + x].path_n != 0) {
				vertex[(y + 1) * n + x].path_n = 0;
				--vertex[(y + 1) * n + x].direction_count;
			}
			if (vertex[y * n + x + 1].path_w != 0) {
				vertex[y * n + x + 1].path_w = 0;
				--vertex[y * n + x + 1].direction_count;
			}
			if (vertex[(y - 1) * n + x].path_s != 0) {
				vertex[(y - 1) * n + x].path_s = 0;
				--vertex[(y - 1) * n + x].direction_count;
			}
			if (vertex[y * n + x - 1].path_e != 0) {
				vertex[y * n + x - 1].path_e = 0;
				--vertex[y * n + x - 1].direction_count;
			}
			pushS(root, g);
			y--;
			k = 1;
		}
		else if (vertex[y * n + x].path_w == 1 && direction <= w && vertex[y * n + x - 1].visited == 0) {
			double roll = diceroll();
			if (roll < CHANCE) {
				addToGraph(graph, y * n + x, y * n + x - 1, w1 + (w2 - w1) * diceroll());
			}
			else {
				addToGraph(graph, y * n + x, y * n + x - 1, w1 + (w2 - w1) * diceroll());
				addToGraph(graph, y * n + x - 1, y * n + x, w1 + (w2 - w1) * diceroll());
			}
			vertex[y * n + x].path_w = 0;
			--vertex[y * n + x].direction_count;
			vertex[y * n + x].visited = 1;
			vertex[y * n + x - 1].path_e = 0;
			--vertex[y * n + x - 1].direction_count;

			if (vertex[(y + 1) * n + x].path_n != 0) {
				vertex[(y + 1) * n + x].path_n = 0;
				--vertex[(y + 1) * n + x].direction_count;
			}
			if (vertex[y * n + x + 1].path_w != 0) {
				vertex[y * n + x + 1].path_w = 0;
				--vertex[y * n + x + 1].direction_count;
			}
			if (vertex[(y - 1) * n + x].path_s != 0) {
				vertex[(y - 1) * n + x].path_s = 0;
				--vertex[(y - 1) * n + x].direction_count;
			}
			if (vertex[y * n + x - 1].path_e != 0) {
				vertex[y * n + x - 1].path_e = 0;
				--vertex[y * n + x - 1].direction_count;
			}
			pushS(root, g);
			x--;
			k = 1;

		}

		else if (vertex[y * n + x].path_s == 1 && direction <= s && vertex[(y + 1) * n + x].visited == 0) {
			double roll = diceroll();
			if (roll < CHANCE) {
				addToGraph(graph, y * n + x, (y + 1) * (n)+x, w1 + (w2 - w1) * diceroll());
			}
			else {
				addToGraph(graph, y * n + x, (y + 1) * (n)+x, w1 + (w2 - w1) * diceroll());
				addToGraph(graph, (y + 1) * n + x, y * n + x, w1 + (w2 - w1) * diceroll());
			}
			vertex[y * n + x].path_s = 0;
			--vertex[y * n + x].direction_count;
			vertex[y * n + x].visited = 1;
			vertex[(y + 1) * n + x].path_n = 0;
			--vertex[(y + 1) * n + x].direction_count;
			if (vertex[(y + 1) * n + x].path_n != 0) {
				vertex[(y + 1) * n + x].path_n = 0;
				--vertex[(y + 1) * n + x].direction_count;
			}
			if (vertex[y * n + x + 1].path_w != 0) {
				vertex[y * n + x + 1].path_w = 0;
				--vertex[y * n + x + 1].direction_count;
			}
			if (vertex[(y - 1) * n + x].path_s != 0) {
				vertex[(y - 1) * n + x].path_s = 0;
				--vertex[(y - 1) * n + x].direction_count;
			}
			if (vertex[y * n + x - 1].path_e != 0) {
				vertex[y * n + x - 1].path_e = 0;
				--vertex[y * n + x - 1].direction_count;
			}
			pushS(root, g);
			y++;
			k = 1;

		}

		else if (vertex[y * n + x].path_e == 1 && direction <= e && vertex[y * n + x + 1].visited == 0) {
			double roll = diceroll();
			if (roll < CHANCE) {
				addToGraph(graph, y * (n)+x, y * (n)+x + 1, w1 + (w2 - w1) * diceroll());
			}
			else {
				addToGraph(graph, y * n + x, y * n + x + 1, w1 + (w2 - w1) * diceroll());
				addToGraph(graph, y * n + x + 1, y * n + x, w1 + (w2 - w1) * diceroll());
			}
			vertex[y * n + x].path_e = 0;
			--vertex[y * n + x].direction_count;
			vertex[y * n + x].visited = 1;
			vertex[y * n + x + 1].path_w = 0;
			--vertex[y * n + x + 1].direction_count;
			if (vertex[(y + 1) * n + x].path_n != 0) {
				vertex[(y + 1) * n + x].path_n = 0;
				--vertex[(y + 1) * n + x].direction_count;
			}
			if (vertex[y * n + x + 1].path_w != 0) {
				vertex[y * n + x + 1].path_w = 0;
				--vertex[y * n + x + 1].direction_count;
			}
			if (vertex[(y - 1) * n + x].path_s != 0) {
				vertex[(y - 1) * n + x].path_s = 0;
				--vertex[(y - 1) * n + x].direction_count;
			}
			if (vertex[y * n + x - 1].path_e != 0) {
				vertex[y * n + x - 1].path_e = 0;
				--vertex[y * n + x - 1].direction_count;
			}
			pushS(root, g);
			x++;
			k = 1;
		}

		else {
			vertex[y * n + x].visited = 1;
			int temp;
			while (vertex[lookS(root)].direction_count == 0) {
				if (lookS(root) == 0) break;
				temp = popS(root);
			}
			temp = popS(root);
			if (temp == 0) {
				break;
			}



			x = temp % (n);
			y = (temp - x) / (n);
			k = 1;
		}

	}
	free(root);
	free(vertex);

	return graph;
}


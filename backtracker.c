#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graf.h"
#include "backtracker.h"
#include "stack.h"

struct Graph* generate_bt(int n, int m, double w1, double w2) {

	vertex_t* vertex = malloc(((n) * (m)) * sizeof * vertex);
	double* wagi = malloc(n * m * sizeof(double));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vertex[i * n + j].visited = 0;
			if ((i - 1 < 0 || i + 1 >= n) && (j - 1 < 0 || j + 1 >= m)) {
				vertex[i * n + j].direction_count = 2;
				if (i - 1 < 0 && j - 1 < 0) {
					vertex[i * n + j].path_n = 0;
					vertex[i * n + j].path_w = 0;
					vertex[i * n + j].path_s = 1;
					vertex[i * n + j].path_e = 1;
				}
				else if (i + 1 >= n && j - 1 < 0) {
					vertex[i * n + j].path_n = 1;
					vertex[i * n + j].path_w = 0;
					vertex[i * n + j].path_s = 0;
					vertex[i * n + j].path_e = 1;
				}
				else if (i - 1 < 0 && j + 1 >= m) {
					vertex[i * n + j].path_n = 0;
					vertex[i * n + j].path_w = 1;
					vertex[i * n + j].path_s = 1;
					vertex[i * n + j].path_e = 0;
				}
				else if (i + 1 >= n && j + 1 >= m) {
					vertex[i * n + j].path_n = 1;
					vertex[i * n + j].path_w = 1;
					vertex[i * n + j].path_s = 0;
					vertex[i * n + j].path_e = 0;
				}
			}
			else if (i - 1 < 0 || j - 1 < 0 || i + 1 >= n || j + 1 >= m) {
				vertex[i * n + j].direction_count = 3;
				if (i - 1 < 0) {
					vertex[i * n + j].path_n = 0;
					vertex[i * n + j].path_w = 1;
					vertex[i * n + j].path_s = 1;
					vertex[i * n + j].path_e = 1;
				}
				if (i + 1 >= n) {
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
				if (j + 1 >= m) {
					vertex[i * n + j].path_n = 1;
					vertex[i * n + j].path_w = 1;
					vertex[i * n + j].path_s = 1;
					vertex[i * n + j].path_e = 0;
				}
			}
			else {
				vertex[i * n + j].direction_count = 4;
				vertex[i * n + j].path_n = 1;
				vertex[i * n + j].path_w = 1;
				vertex[i * n + j].path_s = 1;
				vertex[i * n + j].path_e = 1;
			}
		}
	}

	double direction = 0;
	int k = 1;
	double weigth;
	int x = 0, y = 0;
	int nt = 0, w = 0, s = 0, e = 0;
	int roz = (n) * (m);
	struct Stack* root = createStack(roz);
	struct Graph* graph = createGraph(roz);

	srand(time(NULL));

	while (1 == 1) {
		int i = (vertex[y * n + x].direction_count + 1);
		if (i == 0) i = 1;
		direction = rand() % i;
		weigth = (rand() % 11);
		wagi[y * n + x] = weigth;
		nt = 0;
		w = 0;
		s = 0;
		e = 0;
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
		int g = y * (n)+x;

		if (vertex[y * n + x].path_n == 1 && direction <= nt && vertex[(y - 1) * n + x].visited == 0) {
			addEdge(graph, y * (n)+x, (y - 1) * (n)+x, weigth);
			vertex[y * n + x].path_n = 0;
			--vertex[y * n + x].direction_count;
			vertex[y * n + x].visited = 1;
			vertex[(y - 1) * n + x].path_s = 0;
			--vertex[(y - 1) * n + x].direction_count;
			push(root, g);
			y--;
			k = 1;
			continue;
		}
		else if (vertex[y * n + x].path_w == 1 && direction <= w && vertex[y * n + x - 1].visited == 0) {
			addEdge(graph, y * (n)+x, y * (n)+x - 1, weigth);
			vertex[y * n + x].path_w = 0;
			--vertex[y * n + x].direction_count;
			vertex[y * n + x].visited = 1;
			vertex[y * n + x - 1].path_e = 0;
			--vertex[y * n + x - 1].direction_count;
			push(root, g);
			x--;
			k = 1;
			continue;

		}

		else if (vertex[y * n + x].path_s == 1 && direction <= s && vertex[(y + 1) * n + x].visited == 0) {
			addEdge(graph, y * (n)+x, (y + 1) * (n)+x, weigth);
			vertex[y * n + x].path_s = 0;
			--vertex[y * n + x].direction_count;
			vertex[y * n + x].visited = 1;
			vertex[(y + 1) * n + x].path_n = 0;
			--vertex[(y + 1) * n + x].direction_count;
			push(root, g);
			y++;
			k = 1;
			continue;

		}

		else if (vertex[y * n + x].path_e == 1 && direction <= e && vertex[y * n + x + 1].visited == 0) {
			addEdge(graph, y * (n)+x, y * (n)+x + 1, weigth);
			vertex[y * n + x].path_e = 0;
			--vertex[y * n + x].direction_count;
			vertex[y * n + x].visited = 1;
			vertex[y * n + x + 1].path_w = 0;
			--vertex[y * n + x + 1].direction_count;
			push(root, g);
			x++;
			k = 1;
			continue;

		}
		else {
			int w;
			while (vertex[peek(root)].direction_count == 0) {
				if (peek(root) == 0) break;
				w = pop(root);
			}
			w = pop(root);
			if (w == 0) break;

			x = w % (n);
			y = (w - x) / (n);
			k = 1;
			continue;
		}

	}

	return graph;
}


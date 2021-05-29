#include "matrix.h"
#include "matrix_int.h"
#include "Error.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void* zero;

void* one;

void* sum_int(void* x, void* y) {
	int* a = (int*)x;
	int* b = (int*)y;
	int* c = (int*)calloc(1, sizeof(int));
	*c = *a + *b;
	return (void*)c;
}

void* mult_int(void* x, void* y) {
	int* a = (int*)x;
	int* b = (int*)y;
	int* c = (int*)calloc(1, sizeof(int));
	*c = *a * *b;
	return (void*)c;
}

struct MatrixVoid* create_void0_int() {
	size_t n;
	printf("vveidte n\n");
	scanf_s("%d", &n);

	if (!zero) {
		(int*)zero = (int*)calloc(1, sizeof(int));
		(int*)one = (int*)calloc(1, sizeof(int));
		*(int*)zero = 0;
		*(int*)one = 1;
	}

	struct MatrixVoid* m = calloc(1, sizeof(struct MatrixVoid));
	(int**)m->a = (int**)calloc(n * sizeof(int), sizeof(int));
	for (size_t i = 0; i < n; i++) {
		(int*)m->a[i * sizeof(int)] = (int*)calloc(n * sizeof(int), sizeof(int));
	}
	return create_void0(m, n, sizeof(float), sum_int, mult_int, zero, one, swap_int, div_int, otritsat_int, equal_int);
}

void input_int(struct MatrixVoid* m) {
	int x;
	printf("vvedite matrix with size %d X %d\n", m->n, m->n);
	for (size_t i = 0; i < m->n; i++) {
		for (size_t j = 0; j < m->n; j++) {
			scanf_s("%d", &x);
			setN(m, i, j, &x);
		}
	}
}

void print_int(struct MatrixVoid* m, struct List* list) {
	if (!m) {
		add_error(null_ptr, list);
		list->tail->where_ = calloc(12, sizeof(char));
		list->tail->where_ = "print_float";
		return;
	}
	printf("\n");
	for (size_t i = 0; i < m->n; i++) {
		for (size_t j = 0; j < m->n; j++) {
			int* ptr = (int*)getN(m, i, j);
			printf("%d ", *ptr);
		}
		printf("\n");
	}
}

void swap_int(void* x, void* y) {
	int* a = (int*)(x);
	int* b = (int*)y;
	int c = *a;
	*a = *b;
	*b = c;
}

void* div_int(void* x, void* y) {
	int* a = x;
	int* b = y;
	int* c = calloc(1, sizeof(int));
	*c = *a / *b;
	return (void*)c;
}

void* otritsat_int(void* x) {
	int* a = x;
	int* c = calloc(1, sizeof(int));
	*c = -1 * *a;
	return (void*)c;
}

int equal_int(void* x, void* y) {
	int* a = (int*)x;
	int* b = (int*)y;
	if (*a == *b) return 1;
	else return 0;
}


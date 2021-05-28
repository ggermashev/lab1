#include "matrix.h"
#include "matrix_float.h"
#include "Error.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void* zero;

void* one;

void* sum_float(void* x, void* y) {
	float* a = (float*)x;
	float* b = (float*)y;
	float* c = (float *)calloc(1, sizeof(float));
	*c = *a + *b;
	return (void*)c;
}

void* mult_float(void* x, void* y) {
	float* a = (float*)x;
	float* b = (float*)y;
	float* c = (float*)calloc(1, sizeof(float));
	*c = *a * *b;
	return (void*)c;
}

struct MatrixVoid* create_void0_float() {
	size_t n;
	printf("vveidte n\n");
	scanf_s("%d", &n);
	if (!zero) {
		(float*) zero = (float*)calloc(1, sizeof(float));
		(float*) one = (float*)calloc(1, sizeof(float));
		*(float*)zero = 0.0;
		*(float*)one = 1.0;
	}

	struct MatrixVoid* m = calloc(1, sizeof(struct MatrixVoid));
	(float**)m->a = (float**)calloc(n*sizeof(float), sizeof(float));
	for (size_t i = 0; i < n; i++) {
		(float*)m->a[i*sizeof(float)] = (float*)calloc(n*sizeof(float), sizeof(float));
	}
	return create_void0(m, n, sizeof(float), sum_float, mult_float, zero, one, swap_float, div_float, otritsat_float, equal_float);
}

void input_float(struct MatrixVoid* m) {
	float x ;
	printf("vvedite matrix with size %d X %d\n", m->n, m->n);
	for (size_t i = 0; i < m->n; i++) {
		for (size_t j = 0; j < m->n; j++) {
			scanf_s("%f", &x);
			setN(m, i, j, &x);
		}
	}
}

void print_float(struct MatrixVoid* m, struct List* list) {
	if (!m) {
		add_error(null_ptr, list);
		list->tail->where_ = calloc(12, sizeof(char));
		list->tail->where_ = "print_float";
		return;
	}
	printf("\n");
	for (size_t i = 0; i < m->n; i++) {
		for (size_t j = 0; j < m->n; j++) {
			float* ptr =(float *) getN(m, i, j);
			printf("%f ", *ptr);
		}
		printf("\n");
	}
}

void swap_float(void* x, void* y) {
	float* a = (float*) (x);
	float* b = (float*)y;
	float c = *a;
	*a = *b;
	*b = c;
}

void* div_float(void* x, void* y) {
	float* a = x;
	float* b = y;
	float* c = calloc(1, sizeof(float));
	*c = *a / *b;
	return (void*)c;
}

void* otritsat_float(void* x) {
	float* a = x;
	float* c = calloc(1, sizeof(float));
	*c = -1 * *a;
	return (void*)c;
}

int equal_float(void* x, void* y) {
	float* a = (float*)x;
	float* b = (float*)y;
	if (*a == *b) return 1;
	else return 0;
}

struct MatrixVoid* create_void0_float_test(size_t n) {
	if (!zero) {
		(float*)zero = (float*)calloc(1, sizeof(float));
		(float*)one = (float*)calloc(1, sizeof(float));
		*(float*)zero = 0.0;
		*(float*)one = 1.0;
	}

	struct MatrixVoid* m = calloc(1, sizeof(struct MatrixVoid));
	(float**)m->a = (float**)calloc(n * sizeof(float), sizeof(float));
	for (size_t i = 0; i < n; i++) {
		(float*)m->a[i * sizeof(float)] = (float*)calloc(n * sizeof(float), sizeof(float));
	}
	return create_void0(m, n, sizeof(float), sum_float, mult_float, zero, one, swap_float, div_float, otritsat_float, equal_float);
}

void test_sum_float(struct List* list) {
	struct MatrixVoid* m1 = create_void0_float_test(3);
	struct MatrixVoid* m2 = create_void0_float_test(3);
	srand(time(NULL));
	
	for (size_t i = 0; i < m1->n; i++) {
		for (size_t j = 0; j < m1->n; j++) {
			float x = rand() % 10;
			setN(m1, i, j, &x);
		}
	}

	for (size_t i = 0; i < m2->n; i++) {
		for (size_t j = 0; j < m2->n; j++) {
			float x = rand() % 10;
			setN(m2, i, j, &x);
		}
	}

	printf("m1::\n");
	print_float(m1, list);
	printf("m2::\n");
	print_float(m2, list);

	struct MatrixVoid* m3 = sum_void(m1, m2, list);
	printf("sum::\n");
	print_float(m3, list);
	if (list->head) {
		output_err(list);
		dlt_err(list);
	}

	delete_matrix_void(m1, list);
	delete_matrix_void(m2, list);
	delete_matrix_void(m3, list);
	//-----------------------------------------------------
	 m1 = create_void0_float_test(3);
	 m2 = create_void0_float_test(2);

	for (size_t i = 0; i < m1->n; i++) {
		for (size_t j = 0; j < m1->n; j++) {
			float x = rand() % 10;
			setN(m1, i, j, &x);
		}
	}

	for (size_t i = 0; i < m2->n; i++) {
		for (size_t j = 0; j < m2->n; j++) {
			float x = rand() % 10;
			setN(m2, i, j, &x);
		}
	}

	printf("m1::\n");
	print_float(m1, list);
	printf("m2::\n");
	print_float(m2, list);

	 m3 = sum_void(m1, m2, list);
	printf("sum::\n");
	print_float(m3, list);
	if (list->head) {
		output_err(list);
		dlt_err(list);
	}

	delete_matrix_void(m1, list);
	delete_matrix_void(m2, list);
	delete_matrix_void(m3, list);
}

void test_mult_float(struct List* list) {
	struct MatrixVoid* m1 = create_void0_float_test(3);
	struct MatrixVoid* m2 = create_void0_float_test(3);
	srand(time(NULL));

	for (size_t i = 0; i < m1->n; i++) {
		for (size_t j = 0; j < m1->n; j++) {
			float x = rand() % 10;
			setN(m1, i, j, &x);
		}
	}

	for (size_t i = 0; i < m2->n; i++) {
		for (size_t j = 0; j < m2->n; j++) {
			float x = rand() % 10;
			setN(m2, i, j, &x);
		}
	}

	printf("m1::\n");
	print_float(m1, list);
	printf("m2::\n");
	print_float(m2, list);

	struct MatrixVoid* m3 = mult_void(m1, m2, list);
	print_float(m3, list);
	if (list->head) {
		output_err(list);
		dlt_err(list);
	}

	//--------------------------------------------------

	 m1 = create_void0_float_test(2);
	 m2 = create_void0_float_test(3);
	srand(time(NULL));

	for (size_t i = 0; i < m1->n; i++) {
		for (size_t j = 0; j < m1->n; j++) {
			float x = rand() % 10;
			setN(m1, i, j, &x);
		}
	}

	for (size_t i = 0; i < m2->n; i++) {
		for (size_t j = 0; j < m2->n; j++) {
			float x = rand() % 10;
			setN(m2, i, j, &x);
		}
	}

	printf("m1::\n");
	print_float(m1, list);
	printf("m2::\n");
	print_float(m2, list);

	m3 = mult_void(m1, m2, list);
	print_float(m3, list);
	if (list->head) {
		output_err(list);
		dlt_err(list);
	}


}



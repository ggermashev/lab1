#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "Error.h"
/*
void check_(struct Matrix* m, int i) { 
	if (m->a[i][i] == 0) {
		for (int j = i + 1; j < m->n; j++) {
			if (m->a[j][i] != 0) {
				swap(m, i, j);
			}
		}
	}
}

float det(struct Matrix *m) { //определитель 
	int n = m->n;
	float mn = 1;
	for (int i = 0; i < n; i++) {
		check_(m, i);
		float d = m->a[i][i];
		if (d == 0) return 0;
		for (int j = 0; j < n; j++) {
			m->a[i][j] /= d;
		}
		mn *= d;
		for (int k = i + 1; k < n; k++) {
			float s = -m->a[k][i];
			line_comb(m, k, i, s);
		}
	}
	return mn;
}
*/
struct MatrixVoid * create_void0(struct MatrixVoid *m, size_t n, size_t sz, void* (*sum) (void*, void*), void* (*mult) (void*, void*), void* zero, void* one, void* (*swap)(void*,void*), void* (*div) (void*, void*), void* (*otritsat) (void*), int (*equal) (void*, void*))
{
	m->sum = sum;
	m->mult = mult;
	m->sz = sz;
	m->n = n;
	m->zero = zero;
	m->one = one;
	m->swap = swap;
	m->div = div;
	m->otritsat = otritsat;
	m->equal = equal;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			void *position = getN(m, i, j);
			memcpy(position, m->zero, m->sz); 
		}
	}
	return m;
}

void* getN(struct MatrixVoid* m, size_t i, size_t j) {
	return (void*) (*( (int8_t**)(m->a + i * m->sz)) + j * m->sz);
}

void setN(struct MatrixVoid* m, size_t i, size_t j, void* data) {
	int8_t* pos = getN(m, i, j);
	memcpy(pos, data, m->sz);
}

struct MatrixVoid* sum_void(struct MatrixVoid* m1, struct MatrixVoid* m2, struct List* list) {
	if ((!m1) || (!m2)) {
		add_error(null_ptr, list);
		list->tail->where_ = calloc(9, sizeof(char));
		list->tail->where_ = "sum_void";
		return NULL;
	}
	if ((m1->n != m2->n) || (m1->sz != m2->sz))
	{	
		add_error(dif_size, list);
		list->tail->where_ = calloc(9, sizeof(char));
		list->tail->where_ = "sum_void";
		return NULL ;
	}
	struct MatrixVoid* m3 = create_the_same(m1, list);
	for (size_t i = 0; i < (size_t)m1->n; i++) {
		for (size_t j = 0; j < (size_t)m1->n; j++) {
			void* a = getN(m1, i, j);
			void* b = getN(m2, i, j);
			setN(m3, i, j, m1->sum(a, b));
		}
	}
	return m3;
}

struct MatrixVoid* mult_void(struct MatrixVoid* m1, struct MatrixVoid* m2, struct List* list) {
	if ((!m1) || (!m2)) {
		add_error(null_ptr, list);
		list->tail->where_ = calloc(10, sizeof(char));
		list->tail->where_ = "mult_void";
		return NULL;
	}
	if ( (m1->n != m2->n) || (m1->sz != m2->sz) ) {
		add_error(dif_size, list);
		list->tail->where_ = calloc(10, sizeof(char));
		list->tail->where_ = "mult_void";
		return NULL;
	}
	struct MatrixVoid* m3 = create_the_same(m1, list);
	for (size_t i = 0; i < m3->n; i++) {
		for (int j = 0; j < m3->n; j++) {
			for (int k = 0; k < m3->n; k++) {
				void* a = getN(m3, i, j);
				void* b = m1->mult(getN(m1, i, k), getN(m2, k, j));
				setN(m3, i, j, m1->sum(a, b));
			}
		}
	}
	return m3;
}

void mult_const_void(struct MatrixVoid* m, void* c, struct List* list) {
	if (!m) {
		add_error(null_ptr, list);
		list->tail->where_ = calloc(16, sizeof(char));
		list->tail->where_ = "mult_const_void";
		return ;
	}
	for (size_t i = 0; i < m->n; i++) {
		for (size_t j = 0; j < m->n; j++) {
			setN(m, i, j, m->mult(getN(m, i, j), c));
		}
	}
}

void line_comb_void(struct MatrixVoid* m, size_t num1, size_t num2, void* k, struct List* list) { 
	if (!m) {
		add_error(null_ptr, list);
		list->tail->where_ = calloc(15, sizeof(char));
		list->tail->where_ = "line_comb_void";
		return ;
	}
	for (size_t j = 0; j < m->n; j++) {
		setN(m, num1, j, m->sum(getN(m, num1, j), m->mult(getN(m, num2, j), k)));
	}
}

struct MatrixVoid* inverse_void(struct MatrixVoid* m, struct List *list) { 
	struct MatrixVoid* e = create_the_same(m, list);
	if ((!e) || (!m)) {
		add_error(null_ptr, list);
		list->tail->where_ = calloc(13, sizeof(char));
		list->tail->where_ = "inverse_void";
		return NULL;
	}
	for (size_t i = 0; i < e->n; i++) {
		for (size_t j = 0; j < e->n; j++) {
			if (i == j) {
				setN(e, i, j, e->one);
			}
			else
				setN(e, i, j, e->zero);
		}
	}
	for (size_t i = 0; i < m->n; i++) {
		check0_void(m, i, e);
		if (m->equal(getN(m,i,i),m->zero)) {
			add_error(zero_det, list);
			list->tail->where_ = calloc(13, sizeof(char));
			list->tail->where_ = "inverse_void";
			free(e);
			return NULL;
		}
		for (size_t j = 0; j < m->n; j++) {
			if (j != i) {
				setN(m, i, j, m->div(getN(m, i, j), getN(m, i, i)));
				setN(e, i, j, m->div(getN(e, i, j), getN(m, i, i)));
			}
		}
		setN(e, i, i, m->div(getN(e, i, i), getN(m, i, i)));
		setN(m, i, i, m->div(getN(m, i, i), getN(m, i, i)));
		for (size_t k = 0; k < m->n; k++) {
			if (k != i) {
				line_comb_void(e, k, i, m->otritsat(getN(m, k, i)), list);	
				line_comb_void(m, k, i, m->otritsat(getN(m, k, i)), list);
			}
		}
	}
	return e;
}

void swap_void(struct MatrixVoid* m, size_t i, size_t j) { 
	for (size_t k = 0; k < m->n; k++) {
		void* v1 = getN(m, i, k);
		void* v2 = getN(m, j, k);
		m->swap(v1, v2);
	}
}

void check0_void(struct MatrixVoid* m, size_t i, struct MatrixVoid* e) {
	if (m->equal(getN(m, i, i), m->zero)) {
		for (size_t j = i + 1; j < m->n; j++) {
			if (!(m->equal(getN(m, j, i), m->zero))) {
				swap_void(m, i, j);
				swap_void(e, i, j);
			}
		}
	}
}

void delete_matrix_void(struct MatrixVoid* m, struct List* list) {
	if (!m) {
		add_error(null_ptr, list);
		list->tail->where_ = calloc(19, sizeof(char));
		list->tail->where_ = "delete_matrix_void";
		return;
	}
	if (!m->a) {
		add_error(null_ptr, list);
		list->tail->where_ = calloc(19, sizeof(char));
		list->tail->where_ = "delete_matrix_void";
		return;
	}
	for (size_t i = 0; i < m->n; i++) {
		free(m->a[i]);
	}
	free(m->a);
	free(m);
}

struct MatrixVoid* create_the_same(struct MatrixVoid* m, struct List* list) {
	if (!m) {
		add_error(null_ptr, list);
		list->tail->where_ = calloc(16, sizeof(char));
		list->tail->where_ = "create_the_same";
		return NULL;
	}
	struct MatrixVoid* m1 = calloc(1, sizeof(struct MatrixVoid));
	m1->a = calloc(m->n * m->sz, m->sz);
	for (size_t i = 0; i < m->n; i++) {
		m1->a[i*m->sz] = calloc(m->n * m->sz, m->sz);
	}
	m1 = create_void0(m1, m->n, m->sz, m->sum, m->mult, m->zero, m->one, m->swap, m->div, m->otritsat, m->equal);
	return m1;
}
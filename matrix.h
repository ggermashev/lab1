
#include <stdlib.h>

#ifndef MATRIX_H
#define MATRIX_H

struct MatrixVoid {
	size_t n; 
	void** a;
	void* (*sum) (void*, void*);
	size_t sz;
	void* (*mult) (void*, void*);
	void* zero;
	void* one;
	void* (*swap) (void*, void*);
	void* (*div) (void*, void*);
	void* (*otritsat) (void*);
	int (*equal) (void*, void*);
};

//������� � ������
struct MatrixVoid* create_void0(struct MatrixVoid *m, size_t n, size_t sz, void* (*sum) (void*, void*), void *(*mult) (void*,void*), void *zero, void* one, void* (*swap) (void*,void*), void* (*div) (void*, void*), void* (*otritsat) (void*), int (*equal) (void*, void*));

//����� ������
struct MatrixVoid* sum_void(struct MatrixVoid* m1, struct MatrixVoid* m2, struct List* list);

//�������� ��������� �� ������� �� i,j �������
void* getN(struct MatrixVoid* m, size_t i, size_t j);

//���������� ������� �� i,j �������
void setN(struct MatrixVoid* m, size_t i, size_t j, void* data);

//������������ ������
struct MatrixVoid* mult_void(struct MatrixVoid* m1, struct MatrixVoid* m2, struct List* list);

//��������� ������� �� ���������
void mult_const_void(struct MatrixVoid* m, void* c, struct List* list);

//�������� ���������� ���� �����
void line_comb_void(struct MatrixVoid* m, size_t num1, size_t num2, void* k, struct List* list);

//�������� �������
struct MatrixVoid* inverse_void(struct MatrixVoid* m, struct List* list);

//�������� ������� ��� �������
void swap_void(struct MatrixVoid* m, size_t i, size_t j);

void check0_void(struct MatrixVoid* m, size_t, struct MatrixVoid* e);

//������� �������
void delete_matrix_void(struct MatrixVoid* m, struct List* list);

//������� ������� � ������ �� ���������
struct MatrixVoid* create_the_same(struct MatrixVoid* m, struct List* list);

#endif
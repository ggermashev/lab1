
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

//создать с нулями
struct MatrixVoid* create_void0(struct MatrixVoid *m, size_t n, size_t sz, void* (*sum) (void*, void*), void *(*mult) (void*,void*), void *zero, void* one, void* (*swap) (void*,void*), void* (*div) (void*, void*), void* (*otritsat) (void*), int (*equal) (void*, void*));

//сумма матриц
struct MatrixVoid* sum_void(struct MatrixVoid* m1, struct MatrixVoid* m2, struct List* list);

//получить указатель на элемент на i,j позиции
void* getN(struct MatrixVoid* m, size_t i, size_t j);

//установить элемент на i,j позицию
void setN(struct MatrixVoid* m, size_t i, size_t j, void* data);

//произведение матриц
struct MatrixVoid* mult_void(struct MatrixVoid* m1, struct MatrixVoid* m2, struct List* list);

//умножение матрицы на константу
void mult_const_void(struct MatrixVoid* m, void* c, struct List* list);

//линейная комбинация двух строк
void line_comb_void(struct MatrixVoid* m, size_t num1, size_t num2, void* k, struct List* list);

//обратная матрица
struct MatrixVoid* inverse_void(struct MatrixVoid* m, struct List* list);

//поменять местами две строчки
void swap_void(struct MatrixVoid* m, size_t i, size_t j);

void check0_void(struct MatrixVoid* m, size_t, struct MatrixVoid* e);

//удалить матрицу
void delete_matrix_void(struct MatrixVoid* m, struct List* list);

//создать матрицу с такими же размерами
struct MatrixVoid* create_the_same(struct MatrixVoid* m, struct List* list);

#endif

#ifndef MATRIXFLOAT_H
#define MATRIXFLOAT_H

void* sum_float(void* x, void* y); 

void* mult_float(void* x, void* y);

struct MatrixVoid* create_void0_float();

void print_float(struct MatrixVoid* m, struct List* list);

void input_float(struct MatrixVoid* m);

void swap_float(void* x, void* y);

void* div_float(void*, void*);

void* otritsat_float(void* x);

int equal_float(void*, void*);

struct MatrixVoid* create_void0_float_test(size_t n);

void test_sum_float();

void test_mult_float();

void test_inverse_float();

#endif
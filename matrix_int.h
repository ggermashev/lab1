
#ifndef MATRIXINT_H
#define MATRIXINT_H


void* sum_int(void* x, void* y);

void* mult_int(void* x, void* y);

struct MatrixVoid* create_void0_int();

void print_int(struct MatrixVoid* m, struct List* list);

void input_int(struct MatrixVoid* m);

void swap_int(void*, void*);

void* div_int(void*, void*);

void* otritsat_int(void*);

int equal_int(void*, void*);

void test_sum_int();

void test_mult_int();

void test_line_comb_int();


#endif
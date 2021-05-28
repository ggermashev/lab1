#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrix_float.h"
#include "matrix_int.h"
#include "Error.h"
#include "Tests.h"
int main() 
{
	/*
	struct List* list = create_list();
	
	struct MatrixVoid* m1 = create_void0_float();
	input_float(m1);
	struct MatrixVoid* m2 = inverse_void(m1, list);
	print_float(m2, list);
	struct MatrixVoid* m3 = mult_void(m2, m1, list);
	print_float(m3, list);
	*/
	test_sum();
	test_mult();
	test_inverse();
	test_lineComb();

	/*
	int cnst = 2;

	struct MatrixVoid* m3 = inverse_void(m1,list);
	
	print_float(m3, list );

	//struct MatrixVoid* m2 = sum_void(m3, m3, list);
	m1 = mult_void(m2, m3, list);

	print_float(m2, list );
	
	print_float(m1, list );
	delete_matrix_void(m3, list);
	
	m3 = inverse_void(m1, list);
	print_float(m3, list );
	delete_matrix_void(m3, list);
	delete_matrix_void(m1, list);
	delete_matrix_void(m2, list);

	m1 = create_void0_int();
	m2 = create_void0_int();
	input_int(m1);
	input_int(m2);
	
	m3 = sum_void(m1, m2, list);
	print_int(m3, list);
	delete_matrix_void(m3, list);
	m3 = mult_void(m1, m2, list);
	
	print_int(m3, list);
	mult_const_void(m3, &cnst, list);
	
	print_int(m3, list);
	delete_matrix_void(m3, list);
	delete_matrix_void(m1, list);
	delete_matrix_void(m2, list);

	if (list->head) output_err(list);
	*/
	//test_sum_float(list);
	//test_mult_float(list);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrix_float.h"
#include "matrix_int.h"
#include "Error.h"
#include "Tests.h"

void test_sum()
{
	struct List* list = create_list();
	FILE* file = NULL;
	fopen_s(&file,"Sum.txt", "r");
	
	struct MatrixVoid* m1 = create_void0_float_3();
	struct MatrixVoid* m2 = create_void0_float_3();
	struct MatrixVoid* m3 = create_void0_float_3();

	float x;
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			fscanf_s(file,"%f", &x);
			setN(m1, i, j, &x);
		}
	}
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			fscanf_s(file, "%f", &x);
			setN(m2, i, j, &x);
		}
	}
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			fscanf_s(file, "%f", &x);
			setN(m3, i, j, &x);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int* a = getN(m3, i, j);
			int* b = getN(sum_void(m1, m2, list), i, j);
			if (*a != *b)
			{
				printf_s("Error in test_sum\n");
				fclose(file);
				return;
			}
		}
	}
	fclose(file);
	return;
}

void test_mult()
{
	struct List* list = create_list();
	FILE* file = NULL;
	fopen_s(&file,"Mult.txt", "r");

	struct MatrixVoid* m1 = create_void0_float_3();
	struct MatrixVoid* m2 = create_void0_float_3();
	struct MatrixVoid* m3 = create_void0_float_3();

	float x;
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			fscanf_s(file, "%f", &x);
			setN(m1, i, j, &x);
		}
	}
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			fscanf_s(file, "%f", &x);
			setN(m2, i, j, &x);
		}
	}
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			fscanf_s(file, "%f", &x);
			setN(m3, i, j, &x);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int* a = getN(m3, i, j);
			int* b = getN(mult_void(m1, m2, list), i, j);
			if (*a != *b)
			{
				printf_s("Error in test_mult\n");
				fclose(file);
				return;
			}
		}
	}
	fclose(file);
	return;
}

void test_inverse()
{
	struct List* list = create_list();
	FILE* file = NULL;
	fopen_s(&file, "Inverse.txt", "r");

	struct MatrixVoid* m1 = create_void0_float_3();
	struct MatrixVoid* m2 = create_void0_float_3();


	float x;
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			fscanf_s(file, "%f", &x);
			setN(m1, i, j, &x);
		}
	}
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			fscanf_s(file, "%f", &x);
			setN(m2, i, j, &x);
		}
	}
	struct MatrixVoid* m3 = inverse_void(m1, list);
	//print_float(m2, list);
	//print_float(m3, list);
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			int* a = getN(m2, i, j);
			int* b = getN(m3, i, j);
			//if (*a == -0) *a = +0;
			//if (*b == -0) *b = +0;
			if ((*a > 0 || *a < 0) || (*b > 0 || *b < 0))
			if  (abs(*a - *b) > 0.001) 
			{
				//printf_s("%f %f\n", *a, *b);
				printf_s("Error in test_inverse\n");
				fclose(file);
				//return;
			}
		}
	}
	
	fclose(file);
	return;
}

void test_lineComb()
{
	struct List* list = create_list();
	FILE* file = NULL;
	fopen_s(&file, "LineComb.txt", "r");

	struct MatrixVoid* m1 = create_void0_float_3();
	struct MatrixVoid* m2 = create_void0_float_3();


	float x;
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			fscanf_s(file, "%f", &x);
			setN(m1, i, j, &x);
		}
	}
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			fscanf_s(file, "%f", &x);
			setN(m2, i, j, &x);
		}
	}
	float* k = (float*)calloc(1, sizeof(float));
	*k = 2;
	line_comb_void(m1, 1, 2, k, list);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int* a = getN(m1, i, j);
			int* b = getN(m2, i, j);
			if (*a != *b)
			{
				printf_s("Error in test_lineComb\n");
				fclose(file);
				return;
			}
		}
	}
	fclose(file);
	return;
}

struct MatrixVoid* create_void0_float_3() {
	size_t n = 3;
	
		float* zero = (float*)calloc(1, sizeof(float));
		float* one = (float*)calloc(1, sizeof(float));
		*(float*)zero = 0.0;
		*(float*)one = 1.0;
	

	struct MatrixVoid* m = calloc(1, sizeof(struct MatrixVoid));
	(float**)m->a = (float**)calloc(n * sizeof(float), sizeof(float));
	for (size_t i = 0; i < n; i++) {
		(float*)m->a[i * sizeof(float)] = (float*)calloc(n * sizeof(float), sizeof(float));
	}
	return create_void0(m, n, sizeof(float), sum_float, mult_float, zero, one, swap_float, div_float, otritsat_float, equal_float);
}
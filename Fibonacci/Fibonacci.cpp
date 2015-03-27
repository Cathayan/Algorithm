// Fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


struct Matrix_2by2
{
	int l0r0;
	int l0r1;
	int l1r0;
	int l1r1;
};

struct Matrix_2by2 MatrixMultiple(struct Matrix_2by2 left, struct Matrix_2by2 right)
{
	struct Matrix_2by2 result;
	result.l0r0 = left.l0r0 * right.l0r0 + left.l0r1  *right.l1r0;
	result.l0r1 = left.l0r0 * right.l0r1 + left.l0r1  *right.l1r1;
	result.l1r0 = left.l1r0 * right.l0r0 + left.l1r1  *right.l1r0;
	result.l1r1 = left.l1r0 * right.l0r1 + left.l1r1  *right.l1r1;
	return result;
};

const struct Matrix_2by2 Fibo_factor = {1,1,1,0};


struct Matrix_2by2 Recur_Fibonacci(int index)
{
	if (index == 1)
		return Fibo_factor;
	else return (MatrixMultiple(Recur_Fibonacci(index / 2), Recur_Fibonacci(index - index / 2)));
};

int CalculateFibonacci(int index)
{
	if (index <= 0)
		return 0;
	Matrix_2by2 matrix = Recur_Fibonacci(index);
	return matrix.l0r1;
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


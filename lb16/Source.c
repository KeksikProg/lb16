#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>


void task1() {
	int* ptr_array;
	int size;

	printf("Ведите размерность массива");
	scanf_s("%d", &size);



	ptr_array = (int*)malloc(size * sizeof(int));
	if (ptr_array == NULL) {
		puts("error");
		return -1;
	}

	for (int i = 0; i < size; i++) {
		ptr_array[i] = rand() % 101;
		printf("%d ", ptr_array[i]);
	}

	int last = ptr_array[size - 1];

	printf("Последний элемент: %d\n", last);

	for (int i = 0; i < size; i++) {
		ptr_array[i] += last;
		printf("%d ", ptr_array[i]);
	}

	free(ptr_array);

}

void task2() {
	double* ptr_array;
	int size;

	int choose;

	printf("Ведите размерность массива");
	scanf_s("%d", &size);



	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL) {
		puts("error");
		return -1;
	}



	for (int i = 0; i < size; i++) {

		ptr_array[i] = 1. * (1 - (-1)) * rand() / RAND_MAX + (-1);
		printf("array[%d] = %6.3f\n", i, ptr_array[i]);
	}

	

	printf("Введите с какого значения удалять: ");
	scanf_s("%d", &choose);
	for (int i = 0; i < choose; i++) {
		printf("%6.3f", ptr_array[i]);
	}

	printf("\n");

	double mini = 100000000;
	int index_m = 0;

	for (int i = 0; i < size; i++) {
		if (ptr_array[i] < mini) {
			mini = ptr_array[i];
			index_m = i;
		}
	}

	ptr_array[index_m + 1] = -999;
	for (int i = 0; i < size; i++) {
		printf("%6.3f ", ptr_array[i]);
	}

	

	

	
}

void task3() {
	double* a, *b, *c;
	int size;

	int choose;

	printf("Ведите размерность массива");
	scanf_s("%d", &size);

	
	double* result;

	a = (double*)malloc(size * sizeof(double));
	b = (double*)malloc(size * sizeof(double));
	c = (double*)malloc(size * sizeof(double));
	result = (double*)malloc(size * 3 * sizeof(double));

	if (a == NULL) {
		puts("error");
		return -1;
	}
	if (b == NULL) {
		puts("error");
		return -1;
	}
	if (c == NULL) {
		puts("error");
		return -1;
	}

	for (int i = 0; i < size; i++) {

		a[i] = 1. * (50 - (10)) * rand() / RAND_MAX + (10);
		b[i] = 1. * (50 - (10)) * rand() / RAND_MAX + (10);
		c[i] = 1. * (50 - (10)) * rand() / RAND_MAX + (10);
		
		printf("(a)array[%d] = %6.3f\n", i, a[i]);
	}
	for (int i = 0; i < size; i++){
		printf("(b)array[%d] = %6.3f\n", i, b[i]);
	}
	for (int i = 0; i < size; i++) {
		printf("(c)array[%d] = %6.3f\n", i, c[i]);
	}



	double mini = 100000, maxi=-10000;
	int index_max, index_min;
	for (int i = 0; i < size; i++) {
		if (a[i] < mini) {
			mini = a[i];
			index_min = i;
		}
		if (a[i] > maxi) {
			maxi = a[i];
			index_max = i;
		}
	}


	

	
	for (int i = index_min; i < index_max +1; i++) {
		printf("%6.3f ", a[i]);
	}

	double min_b=100000, max_c=-10000;
	int min_b_index, max_c_index;

	for (int i = 0; i < size; i++) {
		if (min_b > b[i]) {
			min_b = b[i];
			min_b_index = i;
		}
		if (max_c < c[i]) {
			max_c = c[i];
			max_c_index = i;
		}
	}

	for (int i = 0; i <= min_b_index; i++) {
		printf("%6.3f ", b[i]);
	}

	for (int i = max_c_index; i < size; i++) {
		printf("%6.3f ", c[i]);
	}




}

void main() {
	setlocale(LC_ALL, "RUS");
	srand(time(0));

	task3();
}
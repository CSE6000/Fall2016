#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	//Note: This code...
	#pragma omp parallel
	for (i = 0; i < 10; i++)
		printf("i = %d\n", i);

	printf("\n\n");

	//... is not the same as :
	#pragma omp parallel for
	for (i = 0; i< 10; i++)
		printf("i = %d\n", i);\

	printf("\n\n");

	#pragma omp parallel
	#pragma omp for
	for (i = 0; i< 10; i++)
		printf("i = %d, thread_num = %d\n", i, omp_get_thread_num());

	return 0;
}
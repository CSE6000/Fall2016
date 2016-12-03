// $ clang hello_file.c -o hello_file.o
// $ ./hello_file.o
#include <stdio.h>
#include <stdlib.h> 

double* bin2double(char* filepath, double* val, int size);
void double2bin(char* filepath, double* val, int size);

int main()
{
	int size = 10;
	// malloc
	double* val = (double*) malloc(size * sizeof(double));
	// Read
	val = bin2double("./dummy.bin", val, size);
	printf("Hello, File!\n");

	// Check
	for (int i = 0; i < size; ++i)
	{
		printf("%f\n", val[i]);
	}

	// Write
	double2bin("./dummy-tmp.bin", val, size);
	free(val);
	return 0;
}

double* bin2double(char* filepath, double* val, int size)
{
	FILE *fp;
	fp = fopen(filepath, "r");
	fread(val, size, sizeof(double), fp);
	fclose(fp);
	return val;
}

void double2bin(char* filepath, double* val, int size)
{
	FILE *fp;
	fp = fopen(filepath, "w");
	fwrite(val, size, sizeof(double), fp);
	fclose(fp);	
}
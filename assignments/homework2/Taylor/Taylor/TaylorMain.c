#include <stdio.h>
#include <string.h>
// Add your header file

int main(int argc, char* argv[])
{
	//Check argument count
	char errorMsg[] = "usage : Taylor exp(or sin) iter\n";
	if (argc < 3)
	{
		printf("%s\n", errorMsg);
		return 0;
	}

	int iter = atoi(argv[2]);

	if (strcmp(argv[1], "exp") == 0)
	{
		// call myexp()
	}
	else if (strcmp(argv[1], "sin") == 0)
	{
		// call mysin()
	}
	else
	{
		printf("%s is not supported\n", argv[1]);
	}

	return 1;
}
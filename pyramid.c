#include<stdio.h>
#define N 10

int main(int argc, char const *argv[])
{
	int i,j,k;

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N-i; ++j)
		{
			printf(" ");
		}

		for (k = 0; k < 2*i-1; ++k)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}
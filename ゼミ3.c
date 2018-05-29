#include<stdio.h>
#define N 100

int main(int argc, char const *argv[])
{
	
	double x=0.1,y;
	FILE *fp;

	fp=fopen("logi.csv","w");

	for (int i = 0; i < N; ++i)
	{
		y=4*x*(1-x);
		fprintf(fp,"%d,%lf\n",i,y);
		x=y;
	}

	return 0;
}



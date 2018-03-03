#include<stdio.h>

#define X 5
#define Y 1
#define N 16
#define M 20

int main(int argc, char const *argv[])
{
	int m;
	int a[2][2], b[2][2], c[2][2],e=X,f=2,g,h;

	a[0][0]=X;
	a[0][1]=-Y+N;
	a[1][0]=1;
	a[1][1]=0;


	// b[0][0]=a[0][0];
	// b[0][1]=a[0][1];
	// b[1][0]=a[1][0];
	// b[1][1]=a[1][1];

	for (int i = 0; i < 2; ++i)					//上の処理の単純化
	{
		for (int j = 0; j < 2; ++j)
		{
			b[i][j]=a[i][j];
		}
	}


	for (int i = 0; i < M-1; ++i)
	{
		c[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%N;		
		c[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%N;
		c[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%N;
		c[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%N;

		// b[0][0]=c[0][0];
		// b[0][1]=c[0][1];
		// b[1][0]=c[1][0];
		// b[1][1]=c[1][0];

		for (int i = 0; i < 2; ++i)				//上の処理の単純化
		{
			for (int j = 0; j < 2; ++j)
			{
				b[i][j]=c[i][j];
			}
		}



		g=(c[0][0]*X+c[0][1]*2)%N;
		h=(c[1][0]*X+c[1][1]*2)%N;
		
		printf("g = %d\n",g);
	}

	getchar();
	getchar();

	return 0;
}
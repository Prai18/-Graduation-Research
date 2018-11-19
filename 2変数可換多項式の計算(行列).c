#include<stdio.h>
#include<stdlib.h>

#define X 1											
#define Y -1											

#define xX 2											
#define yY 1

#define nN 1
#define N 2											//n乗の値(正確にはm-1乗)

int matrixA[2][2]={{X,Y},
				 	{1,0}};	

int matrixB[2][2]={{X,Y},
				 	{1,0}};

int matrixC[2][2];				 									

void exp_n(int n){
	for (int i = 1; i < n; ++i)
	{
		matrixC[0][0]=matrixA[0][0]*matrixB[0][0]+matrixA[0][1]*matrixB[1][0];
		matrixC[0][1]=matrixA[0][0]*matrixB[0][1]+matrixA[0][1]*matrixB[1][1];
		matrixC[1][0]=matrixA[1][0]*matrixB[0][0]+matrixA[1][1]*matrixB[1][0];
		matrixC[1][1]=matrixA[1][0]*matrixB[0][1]+matrixA[1][1]*matrixB[1][1];

		matrixA[0][0]=matrixC[0][0];
		matrixA[0][1]=matrixC[0][1];
		matrixA[1][0]=matrixC[1][0];
		matrixA[1][1]=matrixC[1][1];
	}
}	


void print_matrix21(int matrix[2][1]){				//2×1の行列の表示
	printf("******結果******\n");
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 1; ++j)
		{
			printf("%2d",matrix[i][j]);
		}
		printf("\n");
	}
}

void print_matrix22(int matrix[2][2]){				//2×2の行列の表示
	printf("******%d乗の行列*******\n",N);
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			printf("%2d",matrix[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int twone[2][1]={{X},
					 {2}};

	int f_matrix[2][1];							//2変数可換多項式のx成分

	int T2,T1;
	int ans;
	// for (int i = 0; i < 5; ++i)
	// {
	// 	printf("%d乗します。\n",i+2);
	// 	exp_m(N);
	// 	print_matrix22(matrixA);
	// }
	
	exp_n(N);											/*|X  Y|
													  	  |1  0|のn乗の計算をする*/
	
	
	print_matrix22(matrixA);

	f_matrix[0][0]=matrixC[0][0]*twone[0][0]+matrixC[0][1]*twone[1][0];					//これ以降は無視していいよ
	f_matrix[1][0]=matrixC[1][0]*twone[0][0]+matrixC[1][1]*twone[1][0];
	print_matrix21(f_matrix);

	T2=f_matrix[0][0];
	T1=f_matrix[1][0];

	ans=(xX*T2-yY*T1)%nN;
	printf("%d\n",nN);
	return 0;
}
#include<stdio.h>
#include<stdlib.h>

#define X 1											
#define Y 1											

#define M_value 3											//m乗の値(正確にはm-1乗)

int m_matrix1[2][2]={{X,-Y},
				 	{1,0}};	

int m_matrix2[2][2]={{X,-Y},
				 	{1,0}};				 									

void exp_m(int m){
	for (int i = 1; i < m-1; ++i)
	{
		m_matrix1[0][0]=m_matrix1[0][0]*m_matrix2[0][0]+m_matrix1[0][1]*m_matrix2[1][0];
		m_matrix1[0][1]=m_matrix1[0][0]*m_matrix2[0][1]+m_matrix1[0][1]*m_matrix2[1][1];
		m_matrix1[1][0]=m_matrix1[1][0]*m_matrix2[0][0]+m_matrix1[1][1]*m_matrix2[1][0];
		m_matrix1[1][1]=m_matrix1[1][0]*m_matrix2[0][1]+m_matrix1[1][1]*m_matrix2[1][1];
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
	printf("******m乗の行列*******\n");
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

	int ans_matrix[2][1];							//2変数可換多項式のx成分

	exp_m(M_value);										/*|X -Y|
													  	  |1  0|のm-1乗の計算をする*/
	
	
	print_matrix22(m_matrix1);

	ans_matrix[0][0]=m_matrix1[0][0]*twone[0][0]+m_matrix1[0][1]*twone[1][0];					//これ以降は無視していいよ
	ans_matrix[1][0]=m_matrix1[1][0]*twone[0][0]+m_matrix1[1][1]*twone[1][0];
	print_matrix21(ans_matrix);

	return 0;
}
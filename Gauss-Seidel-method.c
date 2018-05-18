/*ガウス・ザイデル方を用いた
	連立一次方程式の解*/

#include<stdio.h>
#include<math.h>
#define N 5							//(ア)
#define EPS 1e-6
#define Kmax 30

int main(int argc, char const *argv[])
{
	double a[N][N]={{1.0,4.0,1.0},{2.0,2.0,5.0},{3.0,2.0,1.0}};
	double b[N][N]={{12.0,21.0,10.0}};
	dobule x[N]={0.0,0.0,0.0};
	double dx,sum1,sum2;

	int k=0,i,j;

	do{
		dx=0;
		for ( i = 0; i < N; ++i)
			x[i]=x_new[i];
		for ( i = 0; i < N; ++i){
			sum1=0.0;
			sum2=0.0;
		for ( j = 0; j < /*(イ)*/; ++j)
			sum1+=/*(ウ)*/;
		for ( j = /*(エ)*/; j < N; ++j)
			sum2+=/*(オ)*/;
			x_new[i]=/*(カ)*/;
			dx+=/*(キ)*/;
	}
	k++;

}while(/*(ク)*/);

	if(/*(ケ)*/){
	for(/*(コ)*/)
		printf("x[%d]=%10.4f\n",x_new[i]);
}else
	printf("\n計算中止");
}

#include<stdio.h>
#include<math.h>
#define N 64

int main(int argc, char const *argv[])
{
	int x;
	int y=0;

	printf("xの値をdに入力\n");
	scanf("%d",&x);
	getchar();

	int mod=N;

	int a[N][N],b[N][N];
	int flag[N];

	int hoge;
	int j;

	FILE *fp;
	fp=fopen("2beki.csv","w");

	for (int i = 3; i < N; ++i)
	{
		fprintf(fp, "次数%dの結果\n",i);
		for(j=0;j<N;j++)flag[j]=0;

			for(y=0;y<N;y++){
				a[0][y]=2;
				b[0][y]=1;

				a[1][y]=x;
				b[1][y]=y;

				a[2][y]=(x*x-2*y)%mod;
				b[2][y]=(y*y)%mod;

				a[i][y]=(x*a[i-1][y]-y*a[i-2][y])%mod;
				if(a[i][y]<0) a[i][y]=a[i][y]+mod;

				b[i][y]=(y*b[i-1][y])%mod;
				if(b[i][y]<0) b[i][y]=b[i][y]+mod;
				fprintf(fp, "%d %d\n",a[i][y],b[i][y]);

				//flag check
				hoge=a[i][y];
				flag[hoge]++;
			}
			for(j=0;j<N;j++){
				if(flag[j]!=1)break;
			}
			if(j==N){
				printf("次数%dは重複ではない\n",i);
			}
			getchar();
			fclose(fp);
		return 0;
	}
}
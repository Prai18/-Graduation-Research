#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int x=0;
	int y=0;

	int numx=1;
	int numy=1;

	int deg=256;
	int zero_count=0;

	int cntx[1000]={0};
	int cnty[1000]={0};

	FILE *fp;
	fp=fopen("256.csv","w");

	for (numx=1; numx <= deg; numx++)				//初期条件の変更 numx; -> numx=1;
	{
		x=numx;
		y=0;

		for (numy=1; numy <= deg; numy++)			//初期条件の変更 numy; -> numy=1;
		{
			y=y+1;


			int p=0;

			int za=0;

			int zb=0;

			int zab=0;

			int sa=0;

			int sb=0;

			int ma=20;				//周期を数え始める位置

			int mb=20;

			int mab=20;

			int na=0;

			int nb=0;

			int a[10000];

			int b[10000];

			int as=0;

			int bs=0;

			a[0]=2;
			b[0]=1;

			a[1]=x;
			b[1]=y;

			a[2]=(x*x-2*y)%deg;
			b[2]=(y*y)%deg;


			for (int i = 3; i <= 10000; ++i)
			{
				a[i]=(x*a[i-1]-y*a[i-2])%deg;
				if(a[i]<0)a[i]=a[i]+deg;

				b[i]=(y*b[i-1])%deg;
				if(b[i]<0)b[i]=b[i]+deg; 
			}


			for (int i = ma+1; i < 10000; ++i)
			{
				if(a[ma]==a[i]){
					for (int j = 0; j <= i-ma; ++j)
					{
						if(a[ma+j]==a[i+j]){
							za++;
							if(ma+j==i){
								p=p+1;
								cntx[za-1]++;
								goto END;
							}
						}else{
							za=0;
							break;
						}

					}
				}else if(p==1){
					break;
				}
			}

			END:
			if(za==0){
				printf("x:%d  y:%d\n",numx,numy);
				return 0;
			}

			for (int i = mb+1; i < 10000; ++i)
			{
				if(b[mb]==b[i]){
					for (int j = 0; j < i-mb; ++j)
					{
						if(b[mb+j]==b[i+j]){
							zb++;
							if(mb+j==i){
								p=p+1;
								cnty[zb-1]++;
								goto FIN;
							}
						}else{
							zb=0;
							break;
						}
					}
				}else if(p==1){
					break;
				}
			}

			FIN:

			p=0;
		}
		numy=1;
	}

	for (int i = 1; i < 1000; ++i)
	{
		fprintf(fp,"%d,%d,%d\n",i,cntx[i],cnty[i]);
	}
	fclose(fp);

	scanf("%d",&y);
	return 0;
}
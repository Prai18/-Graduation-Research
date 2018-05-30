#include<stdio.h>

void visited(int i,int n,int v[n+1],int a[n+1][n+1]){
	int j;
	v[i]=1;
	for (j = 0; j <= n; ++j)
	{
		if(/* (ア) */){
		printf("%d->%d\n",i,j);
		visit(j,n,v,a);
	}
}
}

int main(int argc, char const *argv[])
{
	int i,k,n=0;
	FILE *fp;
	scanf("%d",&n);
	int v[n+1];
	for (k = 0; k < n; ++k)
	{
		for (i = 0; i <= n; ++i)
		{
			fscanf(fp,"%d",&a[k][i]);
		} 	
	}
	fclose(/* (イ) */);
	for (k = 0; k <= n; ++k)
	{
		if(/* (ウ) */){
			visit(k,n,v,a);
		}
	}
		return 0;
	}
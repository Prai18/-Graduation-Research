#include<stdio.h>
#define N 5
/*要素を１つ左にシフトさせる*/

void Array_Shift(int *);

int main(int argc, char const *argv[])
{
	int a[N]={1,2,3,4,5};
	int b[5];

	Array_Shift(a);

	for (int i = N-1; i >=0; --i)
	{
		if(i==0){
			b[N-1]=a[i];
		}else{
			b[i-1]=a[i];
		}
	}

	Array_Shift(b);
	return 0;
}

void Array_Shift(int *ar){
	for (int i = 0; i < 5; ++i)
	{
		printf("%d",ar[i]);
	}
		printf("\n");
}

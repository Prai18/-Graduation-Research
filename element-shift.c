#include<stdio.h>
#define N 5
/*要素を１つ左右にシフトさせる*/

void Array(int *);
void Array_Left_Shift(int *);
void Array_Right_Shift(int *);

int b[N];

int main(int argc, char const *argv[])
{
	int a[N]={1,2,3,4,5};
	
	Array(a);

	Array_Left_Shift(a);

	Array(b);

	Array_Right_Shift(a);

	Array(b);
	return 0;
}

void Array(int *ar){
	for (int i = 0; i < 5; ++i)
	{
		printf("%d",ar[i]);
	}
		printf("\n");
}


void  Array_Left_Shift(int *ar){
	
	for (int i = N-1; i >=0; --i)
	{
		if(i==0){
			b[N-1]=ar[i];
		}else{
			b[i-1]=ar[i];
		}
	}
}

void Array_Right_Shift(int *ar){
	for (int i = 0; i < N; ++i)
	{
		if(i==N-1){
			b[0]=ar[i];
		}else{
			b[i+1]=ar[i];
		}
	}
}
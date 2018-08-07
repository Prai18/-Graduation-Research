#include<stdio.h>

/*簡易バブルソート*/

#define N 6

void Bubble_sort(int *);
void swap(int,int);
void ShowData(int *);

int main(int argc, char const *argv[])
{
	int array[N]={6,5,4,3,2,1};


	ShowData(array);
	Bubble_sort(array);
	
	printf("\n");
	ShowData(array);

	return 0;
}

void Bubble_sort(int *array){
	int i, j, temp;

	for( i = 0; i < N-1; i++ ) {
		for( j = N-1; j > i; j-- ) {
			if( array[j-1] > array[j] ) {
				temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
			}
		}
		printf("\n");
		ShowData(array);
	}
}

// void swap(int a,int b){
// 	int tmp;
// 	tmp=a;
// 	a=b;
// 	b=tmp;
// }

void ShowData(int *array){
	for (int i = 0; i < N; ++i)
	{
		printf("%3d",array[i]);
	}
}
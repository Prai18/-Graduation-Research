#include<stdio.h>

/*挿入ソート2	 <アルゴリズムイントロダクション>*/

#define N 5

void insertion_sort(int *,int n);
void ShowData(int *);

int main(int argc, char const *argv[])
{
	int array[N]={6,9,1,10,7};


	ShowData(array);
	
	insertion_sort(array,N);
	
	printf("\n");
	ShowData(array);

	


	return 0;
}

void insertion_sort(int *A,int n){
	int key,i;

	for (int j = 1; j < n; ++j)
	{
		key=A[j];
		i=j-1;

		while(i>=0 && A[i]>key){
			A[i+1]=A[i];
			i=i-1;
		}
		A[i+1]=key;
	}

}



void ShowData(int *array){
	for (int i = 0; i < N; ++i)
	{
		printf("%3d",array[i]);
	}
	printf("\n");
}
#include<stdio.h>

/*挿入ソート*/

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

void insertion_sort(int *array,int n){
	int i, j, temp;

    for (i = 1; i < n; i++) {      /* i 番目の要素をソート済みの配列に挿入 */
        temp = array[i];             /* i 番目の要素を temp に保存 */
        for (j = i; j > 0 && array[j-1] > temp; j--) /* このループで */
            array[j] = array[j -1];                    /* temp を挿入する位置を決める */

        array[j] = temp;             /* temp を挿入 */
        ShowData(array);   /* 途中経過を表示 */
    }
}



void ShowData(int *array){
	for (int i = 0; i < N; ++i)
	{
		printf("%3d",array[i]);
	}
    printf("\n");
}
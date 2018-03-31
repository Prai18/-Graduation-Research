#include<stdio.h>

/*簡易選択ソート*/

#define N 5

void selection_sort(int *,int n);
void ShowData(int *);

int main(int argc, char const *argv[])
{
	int array[N]={3,6,1,10,7};


	ShowData(array);
	
	selection_sort(array,N);
	
	printf("\n");
	ShowData(array);

	


	return 0;
}

void selection_sort(int *array,int n){
	int i; // 配列の先頭を指すインデックス
    int j; // 残りの要素を指すインデックス
    int min; // 最小値を持つ要素のインデックス
    int temp; // 交換用の一時変数

    for (i = 0; i < n-1; i++) {
    	
        min = i; // 配列の先頭を最小値の要素とする
        for (j = i+1; j < n; j++) { // 比較のループ
            if (array[j] < array[min]) {
                min = j; // 最小値を持つ要素を更新
            }
        }
        // 最小値を持つ要素を先頭の要素と交換
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}



void ShowData(int *array){
	for (int i = 0; i < N; ++i)
	{
		printf("%3d",array[i]);
	}
}


/*簡易ヒープソート(熊大院試問題)
			計算時間はＯ(NlogN)*/


#include<stdio.h>
#define N 10

void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void print_array(int *array,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%3d",array[i]);
	}
	printf("\n");
}

void max_heapify(int *a,int i,int n){
	int left,right,largest;
	left=2*i+1;									/*iは親,leftは左の子,rightは右の子*/
	right=2*i+2;						//(ア)

	if(left<n && a[left]>a[i]){					
		largest=left;
	}else{
		largest=i;						//(イ)
	}
	if(right<n && a[right]>a[largest]){
		largest=right;					//(ウ)
	}
	if(largest!=i){
		swap(&a[i],&a[largest]);						/*i,left,rightの中で親の*/
		max_heapify(a,largest,N);		//(エ)			/*iが最大になるまで再帰*/	
	}
}




int main(){
	int i;
	int a[N]={5,6,1,13,2,15,7,9,16,3};
	for (i = N/2; i >=0; --i)				
	{	
		max_heapify(a,i,N);
		print_array(a,N);
	}
	
	return 0;
}
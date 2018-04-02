/*クイックソート(熊大院試問題)
              計算時間はO(NlogN)*/

#include<stdio.h>
#define N 8

void swap(int *x,int *y){
  int i;
  i=*x;*x=*y;*y=i;
  // printf("%d  %d\n",*x,*y);
}

int partition(int *A,int left,int right){
  int i,j,x;
  x=A[right];                                   //(ア)
  i=left-1;
  for(j=left;j<right;j++){
    if(A[j]<=x){                                //(イ)
      i++;
      swap(&A[i],&A[j]);
    }

  }
  swap(&A[i+1],&A[right]);                      //(ウ)
  return i+1;
}

void print_array(int *array){
  int i;
  for(i=0;i<N;i++){
    printf("%3d",array[i]);
  }
   printf("\n");
}


void quicksort(int *A,int left,int right){
  int p;
  if(left>=right) return;
  print_array(A);
  p=partition(A,left,right);
  quicksort(A,left,p-1);                       //(エ)
  quicksort(A,p+1,right);                      //(オ)
}




int main(int argc, char const *argv[])
{
  int A[N]={5,6,2,7,3,8,1,4};
  quicksort(A,0,N-1);
  print_array(A);
  return 0;
}

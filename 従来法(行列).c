#include <stdio.h>
#include<time.h>
#define X 12
#define Y 1
#define K 4      
#define M 10

int pow_o(int k);

int main(void)
{
  int a[2][2]={{X,-Y},{1,0}};
  int b[2][2]={{X,-Y},{1,0}};
  int c[2][2]={{0,0},{0,0}};
  int i,g;
  clock_t start,end;
// 行列のn乗を計算する。
  start=clock();
  printf("(x,y)=(%d,%d)のとき\n\n",X,Y);
 for (int m = 1; m < M-1; ++m)
  {
    c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
    c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
    c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
    c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];

    a[0][0]=c[0][0];
    a[0][1]=c[0][1];
    a[1][0]=c[1][0];
    a[1][1]=c[1][1];
  }

  g=(c[0][0]*X+c[0][1]*2)%pow_o(K);
  printf("T%d(x,y)=(%d,%d)\n",M,X,Y);
  if(g<0){
    printf("remnant=%d\n",g*(-1));
  }else{
    printf("remnant=%d\n",g);
  }
  
  end=clock();

// 行列のn乗を表示する。
  printf("\n%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);

  

  return 0;
}

int pow_o(int k){                 //2^kを求める
  int base=1;
  for (int i = 0; i < k; ++i)
  {
    base*=2;
  }
  return base;
}
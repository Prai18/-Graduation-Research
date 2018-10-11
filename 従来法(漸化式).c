#include<stdio.h>
#include<time.h>
#define M 40

int Tm_x(int m);
int Tm_y(int m);
int pow_o(int k);
void surplus(int huga);

int x=12;                 
int y=1;
int xx;                   //Tm(x,y)のxの値が入る
int yy;                   //Tm(x,y)のyの値が入る
int k=4;                  //2^kの指数k
int m;                    //m次多項式

int piyo;
int remnant;                //余り

clock_t start,end;              //計測用変数


int main(int argc, char const *argv[])
{
    printf("(x,y)=(%d,%d)のとき\n\n",x,y);
  piyo=pow_o(k);

  for (m = 1; m <= M; ++m)          //1,2,3,・・・,mとTm(x,y)のmを変化させていく
  {
    xx=Tm_x(m);
    start=clock();
    yy=Tm_y(m);
    end=clock();
    
  }
  printf("T%d(x,y)=(%d,%d)\n",m-1,x,y);
  surplus(xx);

  
  printf("\n%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);
  return 0;
}


void surplus(int huga){

  remnant=huga%piyo;              //Tm(x,y)%2^k　
    // if(remnant==1){
    //  printf("-----------------------\n");
    // }
  if(remnant<0){                //C言語の特性上無理やり負数の剰余を+に
    remnant+=piyo;
  }
  printf("%3d％%d remnant=%d\n",huga,piyo,remnant);
  
}


int pow_o(int k){                 //2^kを求める
  int base=1;
  for (int i = 0; i < k; ++i)
  {
    base*=2;
  }
  return base;
}


int Tm_x(int m){                  //2変数可換多項式のxの式(再帰関数)
  if(m-1==1){
    return x*x-2*y;
  }
  if(m-1==0){
    return x;
  }
    return x*Tm_x(m-1)-y*Tm_x(m-2);
}

int Tm_y(int m){                  //2変数可換多項式のyの式(再帰関数)
  if(m-1==1){
    return y*y;
  }
  if(m-1==0){
    return y;
  }
  return y*Tm_y(m-1);
}

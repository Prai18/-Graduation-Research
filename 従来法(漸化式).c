#include<stdio.h>
#include<time.h>
#define M 3

int Tm_x(int m);
int Tm_y(int m);
int pow_o(int k);
void surplus_x(int huga);
void surplus_y(int hoge);

int x=0;                 
int y=5;
int xx;                   //Tm(x,y)のxの値が入る
int yy;                   //Tm(x,y)のyの値が入る
int k=4;                  //2^kの指数k
int m;                    //m次多項式
int i=0;
int piyo;
int remnant;                //余り

clock_t start,end;              //計測用変数


int main(int argc, char const *argv[])
{
	piyo=pow_o(k);

while(i!=10){


	
	for (m = 1; m <= M; ++m){          //1,2,3,・・・,mとTm(x,y)のmを変化させていく

  	// start=clock();					//###########ここから###################
  	xx=Tm_x(m);
  	// end=clock();					//###########ここまで計測################
  	yy=Tm_y(m);
  	
  	if(m==M){
  		printf("\n\n(x,y)=(%d,%d)のとき\n\n",x,y);
  		printf("\nT%d(x,y)\n",m);
  		printf("xのmod演算\n");
  		surplus_x(xx);
  		printf("yのmod演算\n");
  		surplus_y(yy);
  		printf("/////////////////////////\n");

  	}

  }
  i++;
}
  // printf("T%d(x,y)=(%d,%d)\n",m-1,x,y);
  // surplus(xx);
	return 0;
}



void surplus_x(int huga){

  remnant=huga%piyo;              //Tm(x,y)%2^k　
    // if(remnant==1){
    //  printf("-----------------------\n");
    // }
  if(remnant<0){                
  	remnant+=piyo;
  }
  printf("%3d％%d remnant=%d\n",huga,piyo,remnant);
  x=remnant;
}

void surplus_y(int hoge){

  remnant=hoge%piyo;              //Tm(x,y)%2^k　
    // if(remnant==1){
    //  printf("-----------------------\n");
    // }
  if(remnant<0){                
  	remnant+=piyo;
  }
  printf("%3d％%d remnant=%d\n",hoge,piyo,remnant);
  y=remnant;
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

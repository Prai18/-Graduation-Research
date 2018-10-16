#include<stdio.h>
#include<stdlib.h>
#define M 3
#define N 16
#define K 16
int Tm_x(int m);
int Tm_y(int m);
int pow_o(int k);
void surplus_x(int huga);
void surplus_y(int hoge);

int x=5;                 
int y=14;
int xx;                   //Tm(x,y)のxの値が入る
int yy;                   //Tm(x,y)のyの値が入る
int m;                    //m次多項式
int i=0;
int piyo;
int remnant;                //余り

int prevx,nextx;			//flag[prevx][prevy][nextx][nexty]
int prevy,nexty;

int flag[N][N][N][N];

int count=0;


int main(int argc, char const *argv[]){

FILE* fp;
  if((fp=fopen("数値解析.csv","w"))==NULL){
        printf("ファイルをオープンできません。\n");
    }

	prevx=x;
	prevy=y;

	piyo=K;

	for (int i = 0; i < N; ++i)						
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				for (int l = 0; l < N; ++l)
				{
          			flag[i][j][k][l]=0;				//flagの初期化
          			// printf("flag[%d][%d][%d][%d]=%d\n",i,j,k,l,flag[i][j][k][l]);
      			}
  			}
		}
}	

// for (int i = 0; i < N; ++i)
// {
// 	for (int j = 0; j < N; ++j)
// 	{
// 		fprintf(fp,"(%d、%d)\n",i,j);
// 	}
// }

while(1){

	for (m = 1; m <= M; ++m){          //1,2,3,・・・,mとTm(x,y)のmを変化させていく

		xx=Tm_x(m);
		yy=Tm_y(m);

		if(m==M){
			printf("\n\n(x,y)=(%d,%d)のとき\n\n",x,y);
			printf("\nT%d(x,y)\n",m);
			printf("xのmod演算\n");
			surplus_x(xx);
			printf("yのmod演算\n");
			surplus_y(yy);
			flag[prevx][prevy][nextx][nexty]+=1;
			printf("/////////////////////////\n");
		}
	}
	if(flag[prevx][prevy][nextx][nexty]==2){
		break;
	}
	prevx=nextx;
	prevy=nexty;
}
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
  nextx=remnant;
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
  nexty=remnant;
}



// int pow_o(int k){                 //2^kを求める
// 	int base=1;
// 	for (int i = 0; i < k; ++i)
// 	{
// 		base*=2;
// 	}
// 	return base;
// }


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

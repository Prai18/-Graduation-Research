#include<stdio.h>
// #include<stdlib.h>

int Tm_x(int k);
int Tm_y(int k);
int pow_o(int k);
void surplus(int huga);

int x=2;									
int y=3;
int xx;										//Tm(x,y)のxの値が入る
int yy;


int k=4;									//2^kの指数k
int m;										//m次多項式
int piyo;
int hoge=1;									//基数
int remnant;								//余り

int main(int argc, char const *argv[])
{
	printf("(x,y)=(%d,%d)のとき\n\n\n",x,y);
	piyo=pow_o(k);

	for (m = 0; m <= 8; ++m)					//1,2,3,・・・,mとTm(x,y)のmを変化させていく
	{
		xx=Tm_x(m);
		yy=Tm_y(m);
		printf("T%d(x,y)=(%d,%d)\n",m,xx,yy);
		surplus(xx);
		surplus(yy);
		printf("\n");
	}
	return 0;
}


void surplus(int huga){

	remnant=huga%piyo;							//Tm(x,y)%2^k　　＊ ^ <- このキャレットは冪の意味
		// if(remnant==1){
		// 	printf("-----------------------\n");
		// }
	if(remnant<0){								//C言語の特性上無理やり負数の剰余を+に
		remnant+=piyo;
	}
	printf("%3d％%d remnant=%d\n",huga,piyo,remnant);
	
}


int pow_o(int k){								//累乗
	for (int i = 0; i < k; ++i)
	{
		hoge*=2;
	}
	return hoge;
}


// int Tm(int m){									//2変数可換多項式のxの式の値
// 	if(m==0){										//ここは必要ないかも
// 		return x;
// 	}
// 	if(m-1==1){
// 		return x*x-2*y;
// 	}
// 	if(m-1==0){
// 		return x;
// 	}
// 	return x*Tm(m-1)-y*Tm(m-2);
// }

int Tm_x(int m){									//2変数可換多項式のxの式
	if(m==0){										//ここは必要ないかも
		return x;
	}
	if(m-1==1){
		return x*x-2*y;
	}
	if(m-1==0){
		return x;
	}
	return x*Tm_x(m-1)-y*Tm_x(m-2);
}

int Tm_y(int m){									//2変数可換多項式のyの式
	if(m==0){										
		return 1;
	}
	if(m-1==1){
		return y*y;
	}
	if(m-1==0){
		return y;
	}
	return y*Tm_y(m-1);
}

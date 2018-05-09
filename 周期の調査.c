#include<stdio.h>
#define N 3										//yの初期値

int main(int argc, char const *argv[])
{
	int y=1;
    int k=4;									//2^k乗のkの値
	unsigned int hoge=1;						//基数
	unsigned int remnant;						//余り

	for (int i = 0; i < k; ++i)
	{
		hoge*=2;
	}


	for (int i = 0; i < 40; ++i)
	{
		remnant=y%hoge;
		if(remnant==1){
			printf("-----------------------\n");
		}
		printf("%3d％%d remnant=%d\n",y,hoge,remnant);
		y*=N;
	}
	return 0;
}
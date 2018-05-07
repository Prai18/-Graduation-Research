#include<stdio.h>


int main(int argc, char const *argv[])
{
	int a=1000;
	int m=1;

	unsigned int decimal;										//10進数
	int binary=0;												//2進数
	int base = 1;

	for (int i = 0; i < 10; ++i)
	{
		a++;
		m*=2;
		decimal=a%m;
		printf("%d ％ %d = %d\n",a,m,decimal);

		  /* 10進数を2進数に変換 */
		while(decimal>0){
			binary = binary + ( decimal % 2 ) * base;
			decimal = decimal / 2;
			base = base * 10;
		}

		  /* 変換した2進数の出力 */
		printf(" 2進数 = %d\n", binary);
	}
	
	return 0;
}
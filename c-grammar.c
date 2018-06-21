/*熊大院試問題*/
#include<stdio.h>

int main(){
	char x='A';
	char y='2';
	char z;
	int a1=0x1392;
	int a2=0x5a17;
	int a3,a4;

	printf("%c %x\n",x,x);

	x=x+19;
	printf("%c %x\n",x,x);

	y=y-49;
	printf("%d\n",y);

	z=065;
	printf("%c\n",z);

	z=x+35;
	printf("%c\n",z);

	z='9';
	printf("%d\n",z);

	a3=a1+a2;
	a4=a1-a2;
	printf("a3=%x\n",a3);
	printf("a4=%x\n",a4);

	return 0;
}

/*実行結果

A　　　41
(ア)　(イ)
1
(ウ)
w
(エ)
a3=(オ)
a4=(カ)

*/


/*
(ア)k
(イ)54
(ウ)
(エ)57
(オ)6da9
(カ)
*/
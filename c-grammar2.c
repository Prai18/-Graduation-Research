/*ポインタの基本的な操作(熊大院試問題)*/
#include<stdio.h>

void func(int *p){
	(*p)+=(*p);
}

int main(void){
	int ary[4]={10,20,30,40};
	int *pt;

	pt=ary;
	printf("a=%d\n",*pt);
	++pt;
	printf("b=%d\n",*(pt+1));
	printf("c=%d\n",*pt+1);
	func(&(*pt));
	printf("d=%d\n",*pt+1);
	return 0;
}


/*実行結果*/
/*
a=10
b=30
c=21
d=41
*/
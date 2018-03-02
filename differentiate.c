#include<stdio.h>

/*differentiate(微分)*/

int main(int argc, char const *argv[])
{
	int a=5,i=3;				//f(x)=ax^i;	a->傾き	i->次数

	printf("f(x)=%dx^%d\n",a,i);

	a*=i;
	i-=1;

	printf("f\'(x)=%dx^%d\n",a,i);
	
	
	return 0;
}
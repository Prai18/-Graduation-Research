#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long UInt64;


#define SEED 1
#define TEST_NUM 5

// srand(SEED);  /////   /////////////


UInt64 Gcd(UInt64 a, UInt64 b){					//GCD

UInt64 r;

if(a<b){
	a=a^b;
	b=a^b;
	a=a^b;
}

while(1){
	r=a%b;
	if(r==0) break;
	a=b;
	b=r;
}

return b;
}

UInt64 AddChain(UInt64 a, UInt64 m, UInt64 n){		//AddChain

	UInt64 y = 1;

	while(m){
		if(m&1) y=y*a%n;
		m=m>>1;
		a=a*a%n;
	}
	return y;
}


UInt64 PrimeGenFermat(void){

	UInt64 p,a,y,i;

	while(1){
		p=rand()%65536|1;
		for (i = 0; i < TEST_NUM; ++i)
		{
			/* code */
			a=rand()%p;
			y=AddChain(a,p-1,p);
			if(y!=1) break;
		}
		if(i>=TEST_NUM) return p;
	}
}

 int main(){
	UInt64 p,q,n,L,e,d,M,C,i=0;

	p= PrimeGenFermat();
	q= PrimeGenFermat();
	n=p*q;                                       //鍵生成
	L=(p-1)*(q-1)/Gcd(p-1,q-1);

	
	while(1){
		e=rand()%L;
		if(Gcd(e,L)==1) break;
		i++;
	}

	while(1){
		if((i*L+1)%e==0) break;
		i++;
	}

	d=(i*L+1)/e;

	printf("p=%llu,q=%llu,n=%llu,L=%llu,e=%llu,d=%llu,\n",p,q,n,L,e,d);

	printf("Message M=?\n");
	scanf("%llu",&M);


	C=AddChain(M,e,n);							//暗号複合
	printf("Cipher text C=%llu\n", C);


	M=AddChain(C,d,n);
	printf("Decrypt Message M=%llu\n", M);

	return 0;
}


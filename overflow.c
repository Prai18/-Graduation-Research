/*オーバーフローの検出(熊大院試問題)*/
#include<stdio.h>
signed short
foo(signed short n){
    signed short i,j;
    for(i=1,j=0;i<=n;i++){
        j=j+1;
    }
    return j;
}

int main(int argc, char const *argv[])
{
    signed short j;
    j=foo(256);
    printf("%d\n",j);
}

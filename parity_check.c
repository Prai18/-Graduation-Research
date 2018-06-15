#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*パリティチェック(熊大院試問題)*/

int BitCount(unsigned char data){               //1の数をカウントする
    int num=0;
    unsigned char mask = /*   (ア)   */;        //最初のビットから

    while(mask!=0){                             //すべてのビットまで
        if(mask&data)num++;
        /*   (イ)   */                           //次のビットへ
    }
    return num;
}

unsigned char AddParityBit(unsigned char data,int flag){        //送信時のパリティ付加
/* flag=0 偶数パリティビット;   flag=1 奇数パリティビットを末尾に付加*/

    int count=0;
    unsigned char retVal;
    count=BitCount(data);

    if(/*   (ウ)   */){
    retVal=data*2;
}else{
        retVal=/*   (エ)   */;
}
return retVal;
}


int ParityCheck(unsigned char data,int flag){       //受信時のパリティチェック
    /* flag=0 偶数, flag=1 奇数パリティチェック*/

    int count=0;
    count=BitCount(data);
    if(/*   (オ)   */){
        printf("パリティエラーなし\n");  return 0;
    }else return -1;                                  //パリティエラーあり
}


// int main(int argc, char const *argv[])           //問題ではmain関数は書かれてないから自分で作ってうごかしてみて
// {                                                //こんな感じで動くと思ったけど...
//     unsigned char binary[]="11010"

//     AddParityBit(binary,0);
//     ParityCheck(binary,0);
//   return 0;
// }


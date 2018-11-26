#include<stdio.h>
#include<stdlib.h>
#define M 5                //m次多項式のm
#define N 64               //flagの大きさ

short int Tm_x(short int m);            //m次の2変数可換多項式のxの値
short int Tm_y(short int m);            //m次の2変数可換多項式のyの値
void surplus_x(short int huga);   //剰余演算x
void surplus_y(short int hoge);   //剰余演算y
void flag_s();              //flagの初期化
short int ****malloc_4dim_array(short int a,short int i,short int u,short int e);       //メモリの確保
void free_4dim_array(short int ****a,short int i,short int u,short int e,short int o);  //メモリの解放

short int x=0;                 
short int y=0;
short int xx;                   //Tm(x,y)のxの値が入る
short int yy;                   //Tm(x,y)のyの値が入る
short int m;                    //m次多項式

short int remnant;                //余り

short int prevx,nextx;            //flag[prevx][prevy][nextx][nexty]
short int prevy,nexty;

short int count=0;      
short int cou;

short int l,ll;

short int ****flag;

short int count1,count2,count4,count8,count16,count32;
short int main(){

    flag=malloc_4dim_array(N,N,N,N);            //メモリの確保

    flag_s();                           //flagの初期化

    for (l = 0; l < N; ++l)
    {
        for (ll = 0; ll < N; ++ll)
        {
            x=l;
            y=ll;

            prevx=x;
            prevy=y;

            while(1){

                for (m = 1; m <= M; ++m){          //1,2,3,・・・,mとTm(x,y)のmを変化させていく

                    xx=Tm_x(m);
                    yy=Tm_y(m);

                    if(m==M){
            // printf("#######################\n");
            // printf("\n\n(x,y)=(%d,%d)のとき\n\n",x,y);
            // printf("\nT%d(x,y)\n",m);
            // printf("xのmod演算\n");
                        surplus_x(xx);
            // printf("yのmod演算\n");
                        surplus_y(yy);
                        flag[prevx][prevy][nextx][nexty]+=1;
            // printf("#######################\n");
                    }
                }
                if(flag[prevx][prevy][nextx][nexty]==2){
                    break;
                }
                prevx=nextx;
                prevy=nexty;
            }

            x=prevx;
            y=prevy;

            flag_s();                           //flagの初期化

            while(1){

                for (m = 1; m <= M; ++m){          //1,2,3,・・・,mとTm(x,y)のmを変化させていく

                    xx=Tm_x(m);
                    yy=Tm_y(m);

                    if(m==M){
            // printf("\n\n(x,y)=(%d,%d)のとき\n\n",x,y);
            // printf("\nT%d(x,y)\n",m);
            // printf("xのmod演算\n");
                        surplus_x(xx);
            // printf("yのmod演算\n");
                        surplus_y(yy);
                        count++;
                        flag[prevx][prevy][nextx][nexty]+=1;
            // printf("/////////////////////////\n");
                    }
                }
                if(flag[prevx][prevy][nextx][nexty]==2){
                    printf("%d\n",count-1);
                    cou=count-1;
                    if(cou==1){
                        count1++;
                    }else if(cou==2){
                        count2++;
                    }else if(cou==4){
                        count4++;
                    }else if(cou==8){
                        count8++;
                    }else if(cou==16){
                        count16++;
                    }else if(cou==32){
                        count32++;
                    }else{
                        printf("2冪以外でちゃった\n");
                    }
                    count=0;
                    break;
                }
                prevx=nextx;
                prevy=nexty;
            }

        }
    }
    printf("周期1の数は→%d\n",count1);
    printf("周期2の数は→%d\n",count2);
    printf("周期4の数は→%d\n",count4);
    printf("周期8の数は→%d\n",count8);
    printf("周期16の数は→%d\n",count16);
    printf("周期32の数は→%d\n",count32);

    free_4dim_array(flag, N, N, N, N);                 //メモリの解放
    return 0;
}


short int ****malloc_4dim_array(short int n1, short int n2, short int n3,short int n4) {          //メモリの確保
  short int ****array;
  array = (short int ****)malloc(n1 * sizeof(short int ***));
  for (short int i = 0; i < n1; i++) {
    array[i] = (short int ***)malloc(n2 * sizeof(short int **));
    for (short int j = 0; j < n2; j++){
      array[i][j] = (short int**)malloc(n3 * sizeof(short int *));
      for(short int k=0;k<n3;k++){
        array[i][j][k] = (short int*)malloc(n4 * sizeof(short int));
        }
    }
}
return array;
}



void free_4dim_array(short int ****array, short int n1, short int n2, short int n3,short int n4) {        //メモリの解放
  for (short int i = 0; i < n1; i++) {
    for (short int j = 0; j < n2; j++){
        for (short int k = 0; k < n3; ++k)
        {
            free(array[i][j][k]);
        }
      free(array[i][j]);
    }
    free(array[i]);
  }
  free(array);
}


void flag_s(){
    for (short int i = 0; i < N; ++i)                     
    {
        for (short int j = 0; j < N; ++j)
        {
            for (short int k = 0; k < N; ++k)
            {
                for (short int l = 0; l < N; ++l)
                {
                    flag[i][j][k][l]=0;             //flagの初期化
                    // printf("flag[%d][%d][%d][%d]=%d\n",i,j,k,l,flag[i][j][k][l]);
                }
            }
        }
    }
}



void surplus_x(short int huga){

  remnant=huga%N;              //Tm(x,y)%2^k　
    // if(remnant==1){
    //  printf("-----------------------\n");
    // }
  if(remnant<0){                
    remnant+=N;
}
// if(f==1){
//     // printf("%3d％%d remnant=%d\n",huga,N,remnant);
// }
x=remnant;
nextx=remnant;
}



void surplus_y(short int hoge){

  remnant=hoge%N;              //Tm(x,y)%2^k　
    // if(remnant==1){
    //  printf("-----------------------\n");
    // }
  if(remnant<0){                
    remnant+=N;
}
// if(f==1){
//     // printf("%3d％%d remnant=%d\n",hoge,piyo,remnant);
// }
y=remnant;
nexty=remnant;
}



short int Tm_x(short int m){                  //2変数可換多項式のxの式(再帰関数)
    if(m-1==1){
        return x*x-2*y;
    }
    if(m-1==0){
        return x;
    }
    return x*Tm_x(m-1)-y*Tm_x(m-2);
}



short int Tm_y(short int m){                  //2変数可換多項式のyの式(再帰関数)
    if(m-1==1){
        return y*y;
    }
    if(m-1==0){
        return y;
    }
    return y*Tm_y(m-1);
}
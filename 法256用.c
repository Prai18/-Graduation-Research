#include<stdio.h>
#include<stdlib.h>
#define M 3                //m次多項式のm
#define N 256               //flagの大きさ
#define K 256               //法の値

int Tm_x(int m);            //m次の2変数可換多項式のxの値
int Tm_y(int m);            //m次の2変数可換多項式のyの値
void surplus_x(int huga);   //剰余演算x
void surplus_y(int hoge);   //剰余演算y
void flag_s();              //flagの初期化
int ****malloc_4dim_array(int a,int i,int u,int e);
void free_4dim_array(int ****a,int i,int u,int e,int o);

int x=0;                 
int y=0;
int xx;                   //Tm(x,y)のxの値が入る
int yy;                   //Tm(x,y)のyの値が入る
int m;                    //m次多項式
int i=0;
int piyo;
int remnant;                //余り

int prevx,nextx;            //flag[prevx][prevy][nextx][nexty]
int prevy,nexty;

int count=0;
int f=1;
int l,ll;

int ****flag;


int main(){

    FILE* fp;
    if((fp=fopen("mod256(m=3).csv","w"))==NULL){
        printf("ファイルをオープンできません。\n");
    }

    flag=malloc_4dim_array(N,N,N,N);            //メモリの確保


    for (l = 0; l < N; ++l)
    {
        for (ll = 0; ll < N; ++ll)
        {

            fprintf(fp,"(%d、%d)",l,ll);
            x=l;
            y=ll;

            prevx=x;
            prevy=y;

            piyo=K;

            flag_s();                           //flagの初期化


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

            f=0;

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
        // printf("\n周期→%d\n\n",count-1);
                    fprintf(fp, ",%d\n", count-1);
                    printf("%d\n",count-1);
                    count=0;
                    break;
                }
                prevx=nextx;
                prevy=nexty;
            }

        }
    }
    fclose(fp);
    free_4dim_array(flag, N, N, N, N);                 //メモリの解放
    return 0;
}


int ****malloc_4dim_array(int n1, int n2, int n3,int n4) {          //メモリの確保
  int ****array;
  array = (int ****)malloc(n1 * sizeof(int ***));
  for (int i = 0; i < n1; i++) {
    array[i] = (int ***)malloc(n2 * sizeof(int **));
    for (int j = 0; j < n2; j++){
      array[i][j] = (int**)malloc(n3 * sizeof(int *));
      for(int k=0;k<n3;k++){
        array[i][j][k] = (int*)malloc(n4 * sizeof(int));
        }
    }
}
return array;
}



void free_4dim_array(int ****array, int n1, int n2, int n3,int n4) {        //メモリの解放
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++){
        for (int k = 0; k < n3; ++k)
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
    for (int i = 0; i < N; ++i)                     
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                for (int l = 0; l < N; ++l)
                {
                    flag[i][j][k][l]=0;             //flagの初期化
                    // printf("flag[%d][%d][%d][%d]=%d\n",i,j,k,l,flag[i][j][k][l]);
                }
            }
        }
    }
}



void surplus_x(int huga){

  remnant=huga%piyo;              //Tm(x,y)%2^k　
    // if(remnant==1){
    //  printf("-----------------------\n");
    // }
  if(remnant<0){                
    remnant+=piyo;
}
if(f==1){
    // printf("%3d％%d remnant=%d\n",huga,piyo,remnant);
}
x=remnant;
nextx=remnant;
}



void surplus_y(int hoge){

  remnant=hoge%piyo;              //Tm(x,y)%2^k　
    // if(remnant==1){
    //  printf("-----------------------\n");
    // }
  if(remnant<0){                
    remnant+=piyo;
}
if(f==1){
    // printf("%3d％%d remnant=%d\n",hoge,piyo,remnant);
}
y=remnant;
nexty=remnant;
}



int Tm_x(int m){                  //2変数可換多項式のxの式(再帰関数)
    if(m-1==1){
        return x*x-2*y;
    }
    if(m-1==0){
        return x;
    }
    return x*Tm_x(m-1)-y*Tm_x(m-2);
}



int Tm_y(int m){                  //2変数可換多項式のyの式(再帰関数)
    if(m-1==1){
        return y*y;
    }
    if(m-1==0){
        return y;
    }
    return y*Tm_y(m-1);
}
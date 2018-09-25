/*行列のn乗*/
#include <stdio.h>
#include <string.h>

int array(int N,int input[2][2]);

int main(void){
    // Your code here!
    int input[2][2]={ {3, 0}, {0, 2} };
    array(3,input);
    
}
int array(int N,int input[2][2]){
    int numput[2][2];
    int i=1;
    if (N>=2){
        numput[0][0]=input[0][0]*input[0][0]+input[0][1]*input[0][1];
        numput[0][1]=input[0][0]*input[0][1]+input[0][1]*input[1][1];
        numput[1][0]=input[1][0]*input[0][0]+input[1][1]*input[0][1];
        numput[1][1]=input[1][0]*input[0][1]+input[1][1]*input[1][1];
        i = i+1;
        for(int i;i<N;i++){
            numput[0][0]=input[0][0]*numput[0][0]+input[0][1]*numput[0][1];
            numput[0][1]=input[0][0]*numput[0][1]+input[0][1]*numput[1][1];
            numput[1][0]=input[1][0]*numput[0][0]+input[1][1]*numput[0][1];
            numput[1][1]=input[1][0]*numput[0][1]+input[1][1]*numput[1][1];
        }
        for(int a=0;a<2;a++){
            printf("{");
            for(int b=0;b<2;b++){
                printf("%d,",numput[a][b]);
            }
            printf("}\n");
        }
    }else{
        for(int a=0;a<2;a++){
            printf("{");
            for(int b=0;b<2;b++){
                printf("%d,",input[a][b]);
            }
            printf("}\n");
        }
    }
}

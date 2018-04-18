#include<stdio.h>

int main(void){
    FILE *fp;
    double pi=3.14159265358979323846;

    /*書き込み*/
    if((fp=fopen("first-excel.csv","w"))==NULL){
        printf("ファイルをオープンできません。\n");
    }else{
        fprintf(fp,"%f",pi);
        fclose(fp);
    }


    /*読み込み*/
    if((fp=fopen("first-excel.csv","r"))==NULL){
        printf("ファイルをオープンできません。\n");
    }else{
        fscanf(fp,"%lf",&pi);
        printf("円周率は%23.21f\n", );
    }
    return 0;
}
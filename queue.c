#include <stdio.h>
 
//  配列の最大の大きさ
#define MAX_LENGTH  100
 
typedef struct{
    //  データを格納数る配列
    int array[MAX_LENGTH];
    //  最初の位置
    int first;
    //  最後の位置
    int last;
}QUEUE;
 
//  スタックの初期化
void init(QUEUE* pQueue)
{
    int i;
    for(i = 0; i < MAX_LENGTH; i++){
        pQueue->array[i] = 0;
    }
    //  最初と最後の位置を先頭に。
    pQueue->first = 0;
    pQueue->last = 0;
}
//  値のプッシュ
int enqueue(QUEUE* pQueue,int value)
{
//  lastの次が、firstならば、失敗
    if((pQueue->last + 1) % MAX_LENGTH == pQueue->first){
        return 0;
    }
    pQueue->array[pQueue->last] = value;          // キューに新しい値を入れる
    pQueue->last = (pQueue->last + 1) % MAX_LENGTH;   // lastの更新
    //  データを格納しきれなかった
    return 1;
}
//  値のポップ
int dequeue(QUEUE* pQueue,int* pValue)
{
    //  キューにデータが一つもないなら、失敗
    if(pQueue->first == pQueue->last)
    {
        return 0;
    }
    *pValue = pQueue->array[pQueue->first];           // いちばん先頭のキューを返す準備
    pQueue->first = (pQueue->first+1) % MAX_LENGTH;   // キューの先頭を次に移動する
    return 1;
 }
 
int main(){
    QUEUE q;
    int value;
    init(&q);   //  スタックを初期化
    //  1,2,3の順で値をプッシュ
    enqueue(&q,1);  
    enqueue(&q,2);
    enqueue(&q,3);
    //  値をポップ
    while(dequeue(&q,&value)){
        printf("%d ",value);
    }
    printf("\n");
}
 


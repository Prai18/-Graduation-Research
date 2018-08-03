#include<stdio.h>
#include<stdlib.h>

/*二分探索木(熊大院試問題)*/

#define N 9

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}Node;

Node *create_node(int key){
    Node *x;
    x=malloc(sizeof(Node));
    x->key=key;
    x->left=NULL;
    x->right=NULL;
    return x;
}

Node *tree_search(Node *x,int k){
    if(x==NULL)return NULL;
    if(x->key==k)return x;                                               //(ア)
    if(x->key<k){                                                        //(イ)
    return tree_search(x->left,k);
}else{
    return tree_search(x->right,k);
}
}

void tree_insert(Node *x,int key){
    if(x->key<=key){
        if(x->right==NULL){
            x->right=create_node(key);  
        }else{
            tree_insert(x->right,key);                                   //(ウ)
        }
    }else{
        if(x->left==NULL){
            x->left=create_node(key);                                    //(エ)
        }else{
            tree_insert(x->left,key);
        }
    }
}

int main(){
    Node *root,*x;
    int array[N]={9,16,8,18,14,3,15,12};
    int i,search_key=12;
    root=create_node(array[0]);
    for(i=1;i<N;i++){
        tree_insert(root,array[i]);
    }
    x=tree_search(root,search_key);
}

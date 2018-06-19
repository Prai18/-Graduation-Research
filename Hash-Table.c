/*熊大院試問題*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define TABLE_SIZE 11
char *strings[]={"AVE","DEF","NUMBER","IF"};

typedef struct CELL{
	char *key;
	struct CELL *next;
}Cell;
	

Cell *table[TABLE_SIZE];						//ハッシュ表


int hash(char *str){							//ハッシュ関数
	int i=0,sum=0,code;
	for (i = 0; i < strlen(str); ++i)
	{
		code=str[i]-'A'+1;
		sum+=code;
	}
	return /* (ア) */;
}


int search(char *key){							//ハッシュ表からデータを探索する
	int h;
	Cell *ptr;
	h=hash(key);
	for(ptr=table[h];ptr!=NULL;ptr=ptr->next){
		if(strcmp(/* (イ) */)==0)return 1;
	}
	return 0;
}


int add(char *key){								//ハッシュ表にデータを追加する
	int h;
	Cell *ptr;
	char *cellkey;
	if(search(key)!=0)return 1;

	ptr=(Cell *)malloc(sizeof(Cell));
	cellkey=(char *)malloc(strlen(key)+1);
	strcpy(cellkey,key);
	h=hash(key);
	ptr->key=cellkey;
	ptr->next=/* (ウ) */
	table[h]=/* (エ) */

	return 0;
}
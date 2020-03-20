#include <stdio.h>
#include <stdbool.h>
//#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long UINT64;


extern void printversion(void);




typedef struct NodeList{
    char data;
    struct NodeList* next;
}NodeList, *pNodeList;

bool ListInit(NodeList* head)
{
    NodeList *p=(NodeList*)malloc(sizeof(NodeList)), *q;
    if(p==NULL){
        return false;
    }
    p->data = 'a';
    head->next = p;
    
    for(int i = 1; i<26; i++){
        q=(NodeList*)malloc(sizeof(NodeList));
        if(q==NULL){
            return false;
        }
        q->data = 'a'+i;
        p->next = q;
        p = q;
    }
    return true;
}

void showList(NodeList* head){
    NodeList *p=head->next;
    for(int i = 1; i<=26; i++){
        printf("%c",p->data);
        p = p->next;
    }
    printf("\n");
}

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int count)
{
    int first, last;
    
    printf("转换前的数组:\n");
    for( first=0; first < count; first++)
    {
        printf("%d ",a[first]);
    }
    
    for( first=0, last=count-1; first < last; first++, last-- )
    {
        inplace_swap(&a[first], &a[last]);
    }
    
    printf("\n转换后的数组:\n");
    for( first=0; first < count; first++)
    {
        printf("%d ",a[first]);
    }
    printf("\n");
}




void shengcheng_s(void);
void shengcheng_d(void);


extern void helpdh(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    //NodeList* head=(NodeList*)malloc(sizeof(NodeList));
    //if(ListInit(head)==true){
    //    showList(head);
    //}
    //int a[7]={1,2,3,4,5,6,7};
    //reverse_array(a, 7);
    
    while(0){
        //shengcheng_s();
        //shengcheng_d();
        //getchar();
    }
    helpdh();
    printversion();    
    
    
    //return 0;
}

void dayun(void){
    int i=abs(rand())%50;
    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep); //已经进行过时区转化为本地时间
    i += p->tm_mon + p->tm_mday + p->tm_hour + p->tm_min + p->tm_sec;
    i = abs(i)%100+6;
    
    while(i--){
        rand();
    }
}

void shengcheng_s(void){
    UINT8 X[6],Y;
    int i,j,temp;
    
    dayun();
    X[0]=abs(rand())%33+1;
    
    do{
        dayun();
        X[1]=abs(rand())%33+1;
    }while(X[1]==X[0]);
    
    do{
        dayun();
        X[2]=abs(rand())%33+1;
    }while(X[2]==X[0]||X[2]==X[1]);
    
    do{
        dayun();
        X[3]=abs(rand())%33+1;
    }while(X[3]==X[0]||X[3]==X[1]||X[3]==X[2]);
    
    do{
        dayun();
        X[4]=abs(rand())%33+1;
    }while(X[4]==X[0]||X[4]==X[1]||X[4]==X[2]||X[4]==X[3]);
    
    do{
        dayun();
        X[5]=abs(rand())%33+1;
    }while(X[5]==X[0]||X[5]==X[1]||X[5]==X[2]||X[5]==X[3]||X[5]==X[4]);
    
    dayun();
    Y=abs(rand())%16+1;
    
    for(i=0;i<5;i++){
        for(j=i+1;j<6;j++){
            if(X[j]<X[i]){
                temp=X[j];
                X[j]=X[i];
                X[i]=temp;
            }
        }
    }
    
    printf("双色球：%d %d %d %d %d %d + %d\n",X[0],X[1],X[2],X[3],X[4],X[5],Y);
}

void shengcheng_d(void){
    UINT8 X[5],Y[2];
    int i,j,temp;
    
    dayun();
    X[0]=abs(rand())%35+1;
    
    do{
        dayun();
        X[1]=abs(rand())%35+1;
    }while(X[1]==X[0]);
    
    do{
        dayun();
        X[2]=abs(rand())%35+1;
    }while(X[2]==X[0]||X[2]==X[1]);
    
    do{
        dayun();
        X[3]=abs(rand())%35+1;
    }while(X[3]==X[0]||X[3]==X[1]||X[3]==X[2]);
    
    do{
        dayun();
        X[4]=abs(rand())%35+1;
    }while(X[4]==X[0]||X[4]==X[1]||X[4]==X[2]||X[4]==X[3]);
    
    dayun();
    Y[0]=abs(rand())%12+1;
    
    do{
        dayun();
        Y[1]=abs(rand())%12+1;
    }while(Y[1]==Y[0]);
    
    for(i=0;i<4;i++){
        for(j=i+1;j<5;j++){
            if(X[j]<X[i]){
                temp=X[j];
                X[j]=X[i];
                X[i]=temp;
            }
        }
    }
    if(Y[1]<Y[0]){
        temp=Y[1];
        Y[1]=Y[0];
        Y[0]=temp;
    }
    printf("大乐透：%d %d %d %d %d + %d %d\n",X[0],X[1],X[2],X[3],X[4],Y[0],Y[1]);
}









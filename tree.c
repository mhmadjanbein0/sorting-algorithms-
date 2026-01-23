#include<stdio.h>
typedef struct nd 
{
    int val;
    struct nd *left,*right;
}node;
typedef struct list 
{
    int val;
    struct list *next;
}list;
int power(int base, int exp)
{
    if(exp==0)
        return base;
    return base*power(base,exp-1);
}
void BUILD_TREE(node *r,list *ls,int height)
{
    if(highL<0)return;
    node *r=(node*)malloc(sizeof(node));
    if(height==0&&ls!=NULL)
    {
        (*r)->val=ls->val;
         ls=ls->next;
    }
    else
          (*r)->val=-1;
        
    BUILD_TREE(&((*R)->Left), L, height - 1);
    BUILD_TREE(&((*R)->Right), L, height - 1);
}

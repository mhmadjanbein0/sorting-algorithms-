#include<stdio.h>
typedef struct node
{
    int val ;
    struct node*left;
    struct node*right;
}node;

void championshion_sort(node*r)
{
    
    if (r->left==NULL && r->right==NULL)  return;
    championshion_sort(r->left);
    championshion_sort(r->right);
    if(r->left->val>r->right->val)
    {
        r->val=r->left->val;
        r->left->val=-1;          
    }
    else{
        r->val=r->right->val;
        r->right->val=-1;  
    }
}
node* create(int val)
{
    node* nd =(node*)malloc(sizeof(node));
    nd->val=val;
    nd->left=nd->right=NULL;
    return nd;
}
node* insert(node*r,int x)
{
    if(r==NULL)
        return create(x);
    else
    {
        if(x>r->val)
          r->right=insert(r->right,x);
        else
          r->left=insert(r->left,x);
    }
}
void insert2(node**r,int x)
{
    if(*r==NULL) 
        *r=create(x);
       
    else
    {
        if(x>(*r)->val)
            insert((*r)->right,x);
        else
          insert((*r)->left,x);
    }
}
void delete_tree(node*r)
{
    if(r==NULL) return;
    delete_tree(r->left);
    delete_tree(r->right);
    free(r);
}
void delete_node(node**r, int x)
{
    if(*r==NULL)return;
    if(x>(*r)->val)
        delete_node(&(*r)->right,x);
    else if(x<(*r)->val)
        delete_node(&(*r)->left,x);
    else
    {
        node*temp;
        if((*r)->left==NULL &&(*r)->right==NULL)
        {
            free(*r);
            *r=NULL;
        }
         else if((*r)->left==NULL)
         {
            temp=(*r)->right;
            free(*r);
            *r=temp;

         }
          else if((*r)->right==NULL)
         {
            temp=(*r)->left;
            free(*r);
            *r=temp;
         }
         else
         {
            node*succ=(*r)->right;
            while(succ->left!=NULL)
                succ=succ->left;
                (*r)->val=succ->val;
                delete_node(&(*r)->right,succ->val);
            

         }
    }
}


#include<stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}
int  partion(int t[],int low,int high)
{
    int pivot = t[low];
    int i=high+1;
    for(int j = high;j>low;j--)
   {
    if (t[j]>pivot) {
        i--;
        swap(&t[i],&t[j]);
        }
   }
    swap(&t[i-1],&t[low]);

    return i-1;
}
 
void quiksort(int t[],int low, int high )
{
    if(low<high)
    {
         int index = partion(t,low,high);
         quiksort(t,low,index-1);
         quiksort(t,index+1,high);

    }
}
void quicksort2(int t[], int low, int high)
{
    if(low<high)
    {
        int pivot = t[high];
        int i=low-1;
        for(int j=low;j<high;j++)
        {
            if(t[j]<=pivot)
            {
                i++;
                swap(&t[i],&t[j]);
            }
        }
        swap(t[i+1],t[low]);
        int pivot_last=i+1;
        quicksort2(t,low,pivot_last-1);
        quicksort2(t,pivot_last+1,high);
    }
}
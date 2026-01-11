#include<stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}
void bubble_sort(int arr[],int n)
{
    int count;
    do{
        count=0;
        for(int i=0;i<n;i++)
            if(arr[i]>arr[i+1])
              {
                swap(&arr[i],&arr[i+1]);
                count=1;
              }
    }while(count);
}
void selection_sort(int arr[],int n)
{
    //one swap per iteration
    int min,j;
    for(int i=0;i<n;i++)
    {
        int min_index=i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[min_index])
                min_index=j;
        swap(&arr[i],&arr[min_index]);
    }
}
void insertion_sort(int arr[],int n)
{
    int i, j ;
    for(i=1;i<n;i++)
    {
        int key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

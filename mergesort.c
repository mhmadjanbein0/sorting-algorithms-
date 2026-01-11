#include<stdio.h>
void merge(int arr[],int low,int high)
{
    if(low>=high)
        return;
    int mid =low+(high-low)/2;
    merge(arr,low,mid);
    merge(arr,mid+1,high);
    int temp[high-low+1];
    int k=0,i=low,j=mid+1;
    while(i<=mid&&j<=high)
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid)
          temp[k++]=arr[i++];
    while(j<=high)
         temp[k++]=arr[j++];
   for(i=0;i<k;i++)
        arr[low+i]=temp[i];
}
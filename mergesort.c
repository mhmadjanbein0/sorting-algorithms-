#include<stdio.h>
void merge1(int arr[],int low,int high)
{
    if(low>=high)
        return;
    int mid =low+(high-low)/2;
    merge1(arr,low,mid);
    merge1(arr,mid+1,high);
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
void mergesort(int arr[], int n) {
    int temp[n];
    int sorted = 0;
    
    while (!sorted) {
        sorted = 1;
        int i = 0;
        
        while (i < n) {
            // Find first sorted run
            int first1 = i;
            while (i + 1 < n && arr[i] <= arr[i + 1])
                i++;
            int last1 = i;
            i++;
            
            // Check if we've reached the end
            if (i >= n) break;
            
            // Find second sorted run
            int first2 = i;
            while (i + 1 < n && arr[i] <= arr[i + 1])
                i++;
            int last2 = i;
            
            // Merge the two runs
            int p1 = first1, p2 = first2, k = first1;
            
            while (p1 <= last1 && p2 <= last2)
                if (arr[p1] <= arr[p2])
                    temp[k++] = arr[p1++];
                else
                    temp[k++] = arr[p2++];
            
            // Copy remaining elements from first run
            while (p1 <= last1)
                temp[k++] = arr[p1++];
            
            // Copy remaining elements from second run
            while (p2 <= last2)
                temp[k++] = arr[p2++];
            
            // Copy merged result back to original array
            for (k = first1; k <= last2; k++)
                arr[k] = temp[k];
            
            sorted = 0;
            i = last2 + 1;
        }
    }
}
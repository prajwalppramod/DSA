#include<stdio.h>
int B[50];
void MergeSort(int A[], int low, int mid, int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high)
    {
        if(A[i]<=A[j])
        {
            B[k]=A[i];
            i++;
            k++;
        }
        else
        {
            B[k]=A[j];
            j++;
            k++;
        }
    }
    
    while(j<=high)
    {
        B[k]=A[j];
        j++;
        k++;
    }
    
    while(i<=mid)
    {
        B[k]=A[i];
        i++;
        k++;
    }
    for(int j=low; j<=high; j++)
    {
        A[j]=B[j];
    }
}


void Merge(int A[],int low, int high)
{   int mid;
    if(low<high)
    {   mid=(low+high)/2;
        Merge(A,low,mid);
        Merge(A,mid+1,high);
        MergeSort(A,low,mid,high);
    }
}

void main()
{
    int size, arr[50];
    printf("Enter size of array:");
    scanf("%d",&size);
    printf("Enter the elements:");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    Merge(arr, 0, size-1);
    printf("Sorted array is \n");
    for(int j=0; j<size; j++)
    {
        printf("%d ", arr[j]);
    }
}
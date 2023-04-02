#include<stdio.h>
void quicksort(int A[], int low, int high);
void MergeSort(int A[], int low, int mid, int high);
void Merge(int A[],int low, int high);

void quicksort(int A[], int low, int high)
{
    int i=low;
    int j=high;
    int pivot=A[(low+high)/2];
    while(i<=j)
    {
        if(A[i]<pivot)
        {
            i++;
        }
        else if(pivot<A[j])
        {
            j--;
        }
        else if(i<=j)
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i++;
            j--;
        }
        else
        {
            break;
        }
    }
    if(low<j)
    {
        quicksort(A,low,j);
    }
    if(i<high)
    {
        quicksort(A,i,high);
    }
}



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
    int choice;
	do {
		printf("\nEnter\n\t1\tQuick Sort\n\t2\tMerge Sort\n\t3\tQuit\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1: 
                printf("Enter size of array:");
                scanf("%d",&size);
                printf("Enter the elements:");
                for(int i=0; i<size; i++)
                {
                    scanf("%d", &arr[i]);
                }
				quicksort(arr, 0, size-1);
				printf("\nSorted array:\t");
				for(int j=0; j<size; j++)
                {
                    printf("%d ", arr[j]);
                }
				break;
			case 2: 
                printf("Enter size of array:");
                scanf("%d",&size);
                printf("Enter the elements:");
                for(int i=0; i<size; i++)
                {
                    scanf("%d", &arr[i]);
                }
				Merge(arr, 0, size-1);
				printf("\nSorted array:\t");
				for(int j=0; j<size; j++)
                {
                    printf("%d ", arr[j]);
                }
				break;
			case 3: break;
			default: printf("\nWrong Choice.\n");
		}
	}while(choice != 3);
}

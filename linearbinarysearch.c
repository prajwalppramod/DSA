#include<stdio.h>
void main()
{
    int arr[50], ch, limit,num,lower,middle,upper;
    printf("Enter limit of array:");
    scanf("%d",&limit);
    printf("Enter elements:");
    for(int i=0; i<limit; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to search:");
    scanf("%d",&num);
    printf("Press 1 for linear search and 2 for binary search");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            for(int i=0; i<limit; i++)
            {
                if(arr[i]==num)
                {
                    printf("Number found at %d",i); 
                    break;
                }
                
            }
            break;
        case 2:
            lower=0;
            upper=limit-1;
            while(lower<=upper)
            {
                middle= (lower+upper)/2;
                if(arr[middle]==num)
                {
                    printf("Number found at %d", middle);
                    break;
                }
                else if(middle>num)
                {
                    upper=middle-1;
                }
                else
                {
                    lower=middle+1;
                }

            }
    }
}
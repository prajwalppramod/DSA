#include<stdio.h>

int stack[50];
int queue[50];
int top=-1;
int front=-1;
int rear=-1;
int flag=0;
void push(int num)
{
    if(top==49)
    {   printf("Stack overflow");
    }
    else
    {   top++;
        stack[top]=num;
    }
}

int pop()
{
    if(top==-1)
    {   
        printf("Stack underflow");
        flag=1;
        return 0;
    }
    else
    {   int x=stack[top];
        top--;
        flag=0;
        return x;

    }
}

void enq(int num)
{
    if(rear==49)
    {
        printf("Queue overflow");
    }
    else
    {
        rear++;
        queue[rear]=num;
        if(front==-1)
            front++;
    }
}

int deq()
{
    if(front==-1)
    {
        printf("Stack underflow");
        return 0;
    }
    else{
        int x=queue[rear];
        rear++;
        return x;
    }
}

void main()
{   int ch,cho,choice;
    printf("Enter choice \n1 for Stack \n2 for Queue \n");
    scanf("%d",&ch);
    switch(ch)
    {   //stack
        case 1:
            do{
                int item;
                printf("Press \n1 to push \n2 to pop \n3 to exit\n");
                scanf("%d",&cho);
                switch(cho)
                {
                    case 1:
                        printf("Enter number to push:");
                        scanf("%d",&item);
                        push(item);
                        break;
                    case 2:
                        item=pop();
                        if(flag==0)    
                            printf("%d \n",item);
                        break;
                    case 3:
                        break;
                    default:
                        printf("Enter valid choice");
                }
            }while(cho!=3);
        case 2:
            do{
                int num;
                printf("Press \n1 to push \n2 to pop \n3 to exit\n");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                        printf("Enter number to push:");
                        scanf("%d",&num);
                        enq(num);
                        break;
                    case 2:
                        num=deq();
                        printf("%d\n",num);
                        break;
                    case 3:
                        break;
                    default:
                        printf("Enter valid choice");
                }
            }while(choice!=3);
            
    }
    
}
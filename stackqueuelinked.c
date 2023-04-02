#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node * next;
};

struct Node* start=NULL, *top=NULL, *front=NULL, *rear=NULL;
void push(int num)
{
    struct Node *newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->data=num;
    newnode->next=top;
    top=newnode;
}

int pop()
{
    if(top==NULL)
    {
        return 0;
    }
    else
    {
        struct Node * temp=top;
        top=top->next;
        int x=temp->data;
        free(temp);
        return x;
    }
}

void dispstck()
{
    if(top==NULL)
    {
        printf("Stack underflow");
    }
    else
    {   
        struct Node *ptr=top;
        while(ptr!=NULL)
        {   printf("%d  ", ptr->data);
            ptr=ptr->next;
        }
    }

}

void enq(int num)
{
    struct Node *newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->data=num;
    newnode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {   rear->next=newnode;
        rear=newnode;
    }
}

int deq()
{
    if(front==NULL)
    {
        return 0;
    }
    else
    {
        int x=front->data;
        struct Node *ptr=front;
        front=front->next;
        free(ptr);
        if(front==NULL)
            rear=NULL;
        return x;
    }
}

void dispque()
{
    if(front==NULL && rear==NULL)
    {
        printf("Queue underflow");
    }
    else
    {
        struct Node *ptr=front;
        while(ptr!=NULL)
        {
            printf("%d ", ptr->data);
            ptr=ptr->next;
        }
    }
}

void main()
{
    int ch,cho,choice;
    printf("Enter choice \n1 for Stack \n2 for Queue \n");
    scanf("%d",&ch);
    switch(ch)
    {   //stack
        case 1:
            do{
                int item;
                printf("Press \n1 to push \n2 to pop \n3 to exit\n4.Display \n");
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
                        if(item!=0)    
                            printf("%d \n",item);
                        else

                        break;
                    case 3:
                        break;
                    case 4:
                            dispstck();
                            break;
                    default:
                        printf("Enter valid choice");
                        break;
                }
            }while(cho!=3);
        case 2:
            do{
                int num;
                printf("Press \n1 to enqueue \n2 to dequeue \n3 to exit\n4.Display");
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
                        if(num!=0)
                        {   printf("%d\n",num);
                        }
                        else
                        {
                            printf("Queue underflow");
                        }
                        break;
                    case 3:
                        break;
                    case 4:
                        dispque();
                        break;
                    default:
                        printf("Enter valid choice");
                }
            }while(choice!=3);
            
    }   
}
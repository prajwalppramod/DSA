#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top=NULL, *front=NULL, *rear=NULL;
void push(int num)
{
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=num;
    newnode->next=top;
    top=newnode;
}
int pop()
{
    if(top==NULL)
    {    return 0;}
    else
    {   struct Node *ptr=top;
        int x=top->data;
        top=top->next;
        free(ptr);
        return x;
    }

}
void dispstck()
{
    if(top==NULL)
        printf("Underflow")
    else
    {   struct Node * ptr=top;
        
    }
}
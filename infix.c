#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<string.h>
#include<math.h>
char I[20];
char P[20];
char S[20]; //infix to postfix putting stack
int top = -1;
int SE[20]; // after postfix, evaluation finding stack
int topev = -1;

int precedenceOS(char c)
{
   switch(c)
   {
    case '+':
    case '-': return 1;

    case '*':
    case '/': return 3;

    case '^': return 6;

   }
}

int precedenceIS(char c)
{
   switch(c)
   {
    case '+':
    case '-': return 2;

     case '*':
    case '/': return 4;

     case '^': return 5;

   }
}

void infixToPostfix(char I[])
{
    int i = 0;
    int j = 0;
    char x , y ;
    while (I[i] != '\0')
    {
        if( isdigit(I[i])) //checking for operand
        {
            P[j++] = I[i]; //simply assigning the infix value if it is an operand
        }

        else if (I[i] == '(')
        {
            //push into stack
            S[++top] = I[i];
        }

        else if (I[i] == ')')
        {
            //pop till )
            while ( S[top] != '(')
            {
                //pop all the elements
                P[j++] = S[top];
                top--;


            }
            top--;
        }
        else //operator case
        {
          x = I[i];  //infix
          y = S[top]; //stack

          if (top == -1 || y == '(' || precedenceIS(y) < precedenceOS(x))
          {
            //push to stack
            S[++top] = I[i];
          }
          else
          {
            while( y != '(' && top != -1 && precedenceOS(x)<= precedenceIS(y))
            {
                //pop the elemnts
                P[j++] = S[top--];
                y=S[top];

            }
            //push
            S[++top] = x;
          }

        }
        i++;
    } //while loop over

    //poping rest elememts in topstack
    while(top != -1)
    {
        P[j++] = S[top--];
        P[j] = '\0';
        printf("THe postfix expression:= %s\n", P);
    }
}

void postfixEvalute()
{
    int i, op1, op2, result;
    char str[10];
    for(i = 0; i < strlen(P); i++) //char to int conv
    {  
        if(isdigit(P[i]))
        {
        str[0] = P[i];
        str[1] = '\0';
        SE[++topev] =  atoi(str);
        }
    
       else //operator
    {
        //pop 2 operands atleast
        op2 = SE[topev--];
        op1 = SE[topev--];

        switch(P[i])
        {
            case '+': result = op1 + op2;
            break;

            case '-': result = op1 - op2;
            break;

            case '*': result = op1 * op2;
            break;

            case '/': result = op1 / op2;
            break;

            case '^': result = pow(op1,op2);
            //break;

        }
        //stack pushing after done with the operation 
        SE[++topev] = result;
        printf("The evaluated expression is = %d\n", result);

    }
}
}

void main()
{
    printf("Enter the infix expression = ");
    scanf("%s", &I);
    //gets(I);

    infixToPostfix(I);
    postfixEvalute(I);

}

// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 20

// char stk[20];
// int top = -1;

// int isEmpty(){
//     return top == -1;
// }
// int isFull(){
//     return top == MAX - 1;
// }


// char peek(){
//     return stk[top];
// }

// char pop(){
//     if(isEmpty())
//         return -1;

//     char ch = stk[top];
//     top--;
//     return(ch);
// }

// void push(char oper){
//     if(isFull())
//         printf("Stack Full!!!!");
   
//     else{
//         top++;
//         stk[top] = oper;
//     }
// }

// int checkIfOperand(char ch) 
// { 
//     return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
// } 

// int precedence(char ch) 
// { 
//     switch (ch) 
//     { 
//     case '+': 
//     case '-': 
//         return 1; 

//     case '*': 
//     case '/': 
//         return 2; 

//     case '^': 
//         return 3; 
//     } 
//     return -1; 
// } 

// int covertInfixToPostfix(char* expression) 
// { 
//     int i, j;

//     for (i = 0, j = -1; expression[i]; ++i) 
//     { 
//        if (checkIfOperand(expression[i])) 
//             expression[++j] = expression[i]; 

//         else if (expression[i] == '(') 
//             push(expression[i]); 

//         else if (expression[i] == ')') 
//         { 
//             while (!isEmpty() && peek() != '(') 
//                 expression[++j] = pop(); 
//             if (!isEmpty() && peek() != '(') 
//                 return -1; // invalid expression              
//             else
//                 pop(); 
//         }
//         else // if an opertor
//         { 
//             while (!isEmpty() && precedence(expression[i]) <= precedence(peek())) 
//                 expression[++j] = pop(); 
//             push(expression[i]); 
//         } 

//     } 

//     while (!isEmpty()) 
//         expression[++j] = pop(); 

//     expression[++j] = '\0'; 
//     printf( "%s", expression); 
// } 

// int main()
// {
// char expression[] = "(a+b)*c+(d-a)"; 
//     covertInfixToPostfix(expression); 
//     return 0; 
// }


//This code include basic operations using stack

#include<stdio.h>
#define size 5
int stack[10];
int top=-1;

void push(int item)
{
    if(top==size-1){
        printf("stack overflow");
    }
    else{
        top=top+1;
        stack[top]=item;
        printf("The value %d is inserted in to the stack \n",stack[top]);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("under flow");
    }
    else{
        int value;
        value=stack[top];
        top=top-1;
        printf("The data %d is poped from stack \n",value);
    }
}

void print()
{
    printf("The values are:");
    for(int i=0;i<=top;i++){
        printf("%d \t",stack[i]);
    }
}

int main()
{
    int choice;
   
    while(1){
         printf("Enter an operator:");
    scanf("%d",&choice); 
    switch(choice){
        case 1: int num;
                printf("Enter a value for insert:");
                scanf("%d",&num);
                push(num);
                break;

        case 2:pop();
        break;
        case 3:print();
        break;
        default:printf("invalid");
        break;        

    }
    }
    

}

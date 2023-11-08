//Check the palindrom using stack


#include<stdio.h>
#define size 10
char stack[10];
int top=-1;

void push(char item)
{
    if(top==size-1){
        printf("stack overflow");
    }
    else{
        top=top+1;
        stack[top]=item;
        printf("The value %c is inserted in to the stack \n",stack[top]);
    }
}

char pop()
{
    if(top==-1)
    {
        printf("under flow");
    }
    else{
        int value;
        value=stack[top];
        top=top-1;
        printf("The data %c is poped from stack \n",value);
        return value;
    }
}

void print()
{
    printf("The string is:");
    for(int i=0;i<=top;i++){
        printf("%c",stack[i]);
    }
}

int Palindrom(char str[])
{
    int check=0;
    int len;
    for(int i=0;str[i]!='\0';i++){
         len++;
    }
    printf("length is %d",len);
    for(int i=0;str[i]!='\0';i++){
         push(str[i]);
         
    }
    for(int i=0;str[i]!='\0';i++){
        char c=pop();
        if(c!=str[i]){
            check++;
              
        }
    }
    return check;

}

int main()
{
   char str[20];
   printf("Enter the string to check palindrom :");
   scanf("%s",str);
   int ch=Palindrom(str);
   print();
   if(ch==0){
    printf("it is palindrom");
   }
   else
   {
    printf("not a palindrom");
   }
}

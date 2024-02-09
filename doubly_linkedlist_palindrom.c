#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

void insert(struct node *head,char val)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->rlink=NULL;

    struct node *ptr=head;

    while(ptr->rlink != NULL)
    {
        ptr=ptr->rlink;
    }

    new->llink=ptr;
    ptr->rlink=new;
}

void display(struct node *head)
{
    struct node *ptr=head->rlink;

    printf("The elements in linkedlist are:");

    while(ptr != NULL)
    {
        printf("%c",ptr->data);
        ptr=ptr->rlink;
    }

  
}

bool palindrom(struct node *head)
{
    struct node *start=head->rlink;
    struct node *end=head;

    while(end->rlink != NULL)
    {
        end=end->rlink;
    }

      while(start != end && start->llink != end)
    {
        if(start->data != end->data)
        {
            return false;
        }
        start=start->rlink;
        end=end->llink;
    }
    return true;
}


int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->llink= NULL;
    head->rlink= NULL;

    char str[10];

    printf("Enter a string to check palindrom:");
    scanf("%s",str);

    for(int i=0 ; str[i] != '\0' ;i++)
    {
        insert(head,str[i]);
    }

    display(head);

    if(palindrom(head))
    {
        printf("yes palindrom");
    }
    else{
        printf("Not a plindrom");
    }
}
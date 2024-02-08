#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *next;
    int coeff;
    int expo;
};

struct node *getdata(int c, int e)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->coeff = c;
    new_node->expo = e;
    return new_node;
}

void insert(struct node *head, int c, int e)
{
    struct node *temp;
    temp = getdata(c, e);

    struct node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
}

void display(struct node *head)
{
    struct node *ptr = head->next;
    while (ptr != NULL)
    {
        if (ptr->expo == 0)
        {
            printf("%d", ptr->coeff);
        }
        else
        {
            if (ptr->coeff != 0)
            {
                printf("%d x^%d +", ptr->coeff, ptr->expo);
            }
        }
        ptr = ptr->next;
    }
    printf("\n");
}


void mul(struct node *p, struct node *q, struct node *r)
{
    struct node *pterm = p->next;
    while (pterm != NULL)
    {
        struct node *qterm = q->next;
        while (qterm != NULL)
        {
            struct node *temp = getdata(0, 0);
            temp->coeff = pterm->coeff * qterm->coeff;
            temp->expo = pterm->expo + qterm->expo;
            if (temp->coeff != 0)
            {
                insert(r, temp->coeff, temp->expo);
            }
            qterm = qterm->next;
        }
        pterm = pterm->next;
    }
}

int main()
{
    struct node *p;
    struct node *q;
    struct node *r;

    p = getdata(0, 0);
    q = getdata(0, 0);
    r = getdata(0, 0);

    int term1, term2, e, c;

    printf("Enter the number of terms of 1st polynomial: ");
    scanf("%d", &term1);

    for (int i = 0; i < term1; i++)
    {
        printf("Enter coeff(%d): ", i + 1);
        scanf("%d", &c);
        printf("Enter expo(%d): ", i + 1);
        scanf("%d", &e);

        insert(p, c, e);
    }
    printf("1st polynomial: ");
    display(p);

    printf("\nEnter the number of terms of 2nd polynomial: ");
    scanf("%d", &term2);

    for (int i = 0; i < term2; i++)
    {
        printf("Enter coeff(%d): ", i + 1);
        scanf("%d", &c);
        printf("Enter expo(%d): ", i + 1);
        scanf("%d", &e);

        insert(q, c, e);
    }
    printf("2nd polynomial: ");
    display(q);

    mul(p, q, r);
    printf("\nThe multiplication result: ");
    display(r);

    return 0;
}

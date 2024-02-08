#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff,expo,yexpo;
    struct node *next;
};

struct node *getdata(int c,int e,int ey)
{
    struct node *new_node=(struct node*)malloc (sizeof(struct node));
    new_node->next=NULL;
    new_node->coeff=c;
    new_node->expo=e;
    new_node->yexpo=ey;
    return new_node;
}

void insert(struct node *head,int c,int e,int ey)
{
    struct node *temp;
    temp=getdata(c,e,ey);
    struct node *ptr=head;
    while(ptr->next !=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next = temp;
}


void display(struct node *poly)
{
    while (poly != NULL)
    {
        if (poly->expo != 0) {
            printf("%d", poly->coeff);
            if (poly->expo != 1) {
                printf("x^%d", poly->expo);
            }
            if (poly->yexpo != 0) {
                printf("y^%d", poly->yexpo);
            }
            if (poly->next != NULL && poly->next->expo != 0)
            {
                printf(" + ");
            }
        } else if (poly->yexpo != 0) {
            // If exponent is 0, print only the constant term if y is present
            printf("%d", poly->coeff);
            if (poly->yexpo != 1) {
                printf("y^%d", poly->yexpo);
            }
            
            if (poly->next != NULL && poly->next->expo != 0)
            {
                printf(" + ");
            }
            else if(poly->expo == 0 && poly->yexpo != 0 )
            {
                printf("%d",poly->coeff);
            }
            
        }
        poly = poly->next;
    }
    printf("\n");
}

struct node *addPolynomials(struct node *p, struct node *q) {
    struct node *result = getdata(0, 0, 0); // Initialize the result polynomial with a dummy node
    struct node *ptr1 = p->next; // Skip the dummy node of p
    struct node *ptr2 = q->next; // Skip the dummy node of q
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->expo == ptr2->expo && ptr1->yexpo == ptr2->yexpo) {
            int sumCoeff = ptr1->coeff + ptr2->coeff;
            if (sumCoeff != 0) {
                insert(result, sumCoeff, ptr1->expo, ptr1->yexpo);
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if ((ptr1->expo > ptr2->expo) || (ptr1->expo == ptr2->expo && ptr1->yexpo > ptr2->yexpo)) {
            insert(result, ptr1->coeff, ptr1->expo, ptr1->yexpo);
            ptr1 = ptr1->next;
        } else {
            insert(result, ptr2->coeff, ptr2->expo, ptr2->yexpo);
            ptr2 = ptr2->next;
        }
    }
    // Append remaining terms of p or q if any
    while (ptr1 != NULL) {
        insert(result, ptr1->coeff, ptr1->expo, ptr1->yexpo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) {
        insert(result, ptr2->coeff, ptr2->expo, ptr2->yexpo);
        ptr2 = ptr2->next;
    }
    return result;
}


int main()
{
    struct node *p,*q,*r;
    p=getdata(0,0,0);
    q=getdata(0,0,0);
    r=getdata(0,0,0);

    int term,term1,c,e,ey,c1,e1,ey1;

    printf("Enter number of terms of 1st matrix:");
    scanf("%d",&term);

    for(int i=0;i<term;i++)
    {
        printf("Enter coeff(%d):",i+1);
        scanf("%d",&c);
        printf("Enter expo(%d):",i+1);
        scanf("%d",&e);
        printf("Enter y exponent(%d):",i+1);
        scanf("%d",&ey);

        insert(p,c,e,ey);
    }
    display(p);

    printf("Enter number of terms of 2nd matrix:");
    scanf("%d",&term1);

    for(int i=0;i<term1;i++)
    {
        printf("Enter coeff(%d):",i+1);
        scanf("%d",&c1);
        printf("Enter expo(%d):",i+1);
        scanf("%d",&e1);
        printf("Enter y exponent(%d):",i+1);
        scanf("%d",&ey1);

        insert(q,c1,e1,ey1);
    }

    display(q);

    struct node *result = addPolynomials(p, q);
    printf("Resultant polynomial: ");
    display(result);
}
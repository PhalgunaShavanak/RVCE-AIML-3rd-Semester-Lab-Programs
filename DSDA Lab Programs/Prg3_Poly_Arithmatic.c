#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int power;
    struct node *link;
};

struct node *poly1;
struct node *poly2;

void poly1insert()
{
    struct node *newnode;
    struct node *ptr1;
    int co, pow;
    while(1)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the co-efficient: ");
        scanf("%d", &co);
        newnode->coeff = co;
        printf("Enter the power: ");
        scanf("%d", &pow);
        newnode->power = pow;
        newnode->link = NULL;

        if(poly1 == NULL)
        {
            poly1 = newnode;
        }
        else
        {
            ptr1 = poly1;
            while(ptr1->link!=NULL)
            {
                ptr1 = ptr1->link;
            }
            ptr1->link = newnode;
        }
        printf("Do you want to add more terms: Yes == 1/ No ==0: ");
        int flag;
        scanf("%d", &flag);
        if(flag == 0)
            break;
    }

}

void poly2insert()
{
    struct node *newnode;
    struct node *ptr2;
    int co, pow;
    while(1)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the co-efficient: ");
        scanf("%d", &co);
        newnode->coeff = co;
        printf("Enter the power: ");
        scanf("%d", &pow);
        newnode->power = pow;
        newnode->link = NULL;

        if(poly2 == NULL)
        {
            poly2 = newnode;
        }
        else
        {
            ptr2 = poly2;
            while(ptr2->link!=NULL)
            {
                ptr2 = ptr2->link;
            }
            ptr2->link = newnode;
        }
        printf("Do you want to add more terms: Yes == 1/ No ==0: ");
        int flag;
        scanf("%d", &flag);
        if(flag == 0)
            break;
    }

}

void displaypoly(struct node *poly)
{
    struct node *next;
    printf("%dx^%d ", poly->coeff, poly->power);
    next = poly->link;
    while(next != NULL)
    {
        printf("+ %dx^%d ", next->coeff, next->power);
        next = next->link;
    }
}

void addnum()
{
    struct node *next1;
    struct node *next2;
    int coefftemp;
    next1 = poly1;
    next2 = poly2;
    while(next1!=NULL)
    {
        while(next2!=NULL)
        {
            if(next1->power == next2->power)
            {
                coefftemp = next1->coeff + next2->coeff;
                printf("(%dx^%d) ", coefftemp,next1->power);
            }
            next2 = next2->link;
        }
        next2 = poly2;
        next1 = next1->link;
        if(next1 != NULL)
        {
            printf("+ ");
        }
    }
}

void multiply()
{
    struct node *next1;
    struct node *next2;
    int powtemp;
    int coefftemp;
    next1 = poly1;
    next2 = poly2;
    while(next1!=NULL)
    {
        while(next2!=NULL)
        {
            powtemp = next1->power + next2->power;
            coefftemp = next1->coeff * next2->coeff;
            printf("(%dx^%d) + ", coefftemp, powtemp);
            next2 = next2->link;
        }
        next2 = poly2;
        next1 = next1->link;
    }
}

int main()
{
    printf("Enter the first expression:\n");
    poly1insert();
    printf("\nEnter the second expression:\n");
    poly2insert();
    printf("\nThe first expression is:\n");
    displaypoly(poly1);
    printf("\nThe second expression is:\n");
    displaypoly(poly2);
    printf("\nThe sum of the expression is:\n");
    addnum();
    printf("\nThe product of the expression is:\n");
    multiply();
    return 0;
}
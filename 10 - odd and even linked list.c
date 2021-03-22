#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int data;
    struct nodetype *next;
} node;

void insert(node **, node **);
void display(node *);

int main()
{
    node *even = NULL, *odd = NULL;
    int ch = 1;
    while (ch >= 1 && ch <= 3)
    {
        printf("\n1: insert\n2: display lists\n[Else Exit]\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            insert(&even, &odd);
        if (ch == 2)
        {
            printf("Even nodes: ");
            display(even);
            printf("Odd nodes: ");
            display(odd);
        }
    }
    return 0;
}

void insert(node **even, node **odd)
{
    node *P = malloc(sizeof(node));
    printf("Enter element: ");
    scanf("%d", &P->data);

    if (P->data % 2 == 0)
    {
        P->next = *even;
        *even = P;
    }
    else
    {
        P->next = *odd;
        *odd = P;
    }
}

void display(node *P)
{
    while (P != NULL)
    {
        printf("%d ", P->data);
        P = P->next;
    }
    printf("\n");
}
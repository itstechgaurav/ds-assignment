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
    int ch = 1;
    node *L = NULL, *R = NULL;

    while (ch >= 1 && ch <= 2)
    {
        printf("\n1: insert\n2: display\n[Else Exit]\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            insert(&L, &R);
        if (ch == 2)
            display(L);
    }
}

void insert(node **L, node **R)
{
    node *P = malloc(sizeof(node)), *T;
    printf("Enter a element: ");
    scanf("%d", &P->data);

    if (*L == NULL && *R == NULL)
    {
        *L = *R = P;
    }
    else if (P->data < (*L)->data)
    {
        P->next = *L;
        *L = P;
    }
    else if (P->data > (*R)->data)
    {
        (*R)->next = P;
        (*R) = P;
    }
    else
    {
        T = *L;
        while (T->next->data < P->data)
            T = T->next;

        P->next = T->next;
        T->next = P;
    }
}

void display(node *L)
{
    while (L != NULL)
    {
        printf("%d ", L->data);
        L = L->next;
    }
}
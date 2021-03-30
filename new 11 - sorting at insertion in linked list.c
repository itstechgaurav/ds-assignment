#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int data;
    struct nodetype *next;
    struct nodetype *back;
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
    P->back = P->next = NULL;

    if (*L == NULL) // if we are inserting first node
    {
        *L = *R = P; // both share the same address
    }
    else
    {
        T = *L;
        // finding where to insert the new node
        while (T != NULL)
        {
            if (T->data > P->data)
                break;
            T = T->next; // untill then move T to next
        }
        if (T == NULL)
        {
            // if t is null that means we will insert right side
            (*R)->next = P; // p will be r's next
            P->back = *R;   // p's back will be R
            (*R) = P;       // now R will move to the P
        }
        else if (*L == T)
        {
            // if P is equal to L that means we will insert
            // before left node
            P->next = *L;   // p's next will be L
            (*L)->back = P; // l's back will be P
            *L = P;         // L will move to P
        }
        else
        {
            // else we are inserting in b/w list
            T->back->next = P; // T's back ->next will now be P
            P->back = T->back; // and P's Back will Be T's Back
            P->next = T;       // P's next will be the T
            T->back = P;       // and t's back will be P
        }
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
#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int data;
    struct nodetype *next;
} node;

node *insert(node *);
node *reverse(node *, node *);
void display(node *);

int main()
{
    node *L = NULL, *R = NULL;
    int ch = 1;

    while (ch >= 1 && ch <= 3)
    {
        printf("\n1: insert\n2: Reverse\n3: display\n[Else Exit]\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            R = insert(R);
            if (L == NULL)
                L = R;
        }
        if (ch == 2)
        {
            R = L;                // now left is the right
            L = reverse(NULL, L); // and we will get new left
        }

        if (ch == 3)
            display(L);
    }
    return 0;
}

node *insert(node *R)
{
    node *P = malloc(sizeof(node));
    printf("Enter a number: ");
    scanf("%d", &P->data);

    P->next = NULL;
    if (R == NULL)
    {
        R = P;
    }
    else
    {
        R->next = P;
        R = P;
    }
    return R;
}

node *reverse(node *P, node *C)
{
    // reversing and returning the last node of the list
    node *res = C->next != NULL ? reverse(C, C->next) : C;
    C->next = P; // moving the Current->next = Parent
    return res;  // returning the last node of the list
}

void display(node *L)
{
    while (L != NULL)
    {
        printf("%d ", L->data);
        L = L->next;
    }
}
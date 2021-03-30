#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int data;
    struct nodetype *next;
} node;

node *insert(node *, node *);
void display(node *);

int main()
{
    node *O = NULL, *P = NULL, *N = NULL; // O - original, P - positive, N - negative
    int ch = 1;

    while (ch >= 1 && ch <= 2)
    {
        printf("\n1: create\n2: display all Lists\n[Else Exit]\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            O = insert(O, NULL);
        if (ch == 2)
        {
            P = insert(O, O);
            N = (P + 1); // first index of p having the negative node
            printf("Original List: ");
            display(O);
            printf("\nPositive List: ");
            display(P);
            printf("\nNegative List: ");
            display(N);
        }
    }
    return 0;
}

node *insert(node *O, node *FROM)
{
    node *POS = NULL, *NEG = NULL;
    node *P = NULL;

    if (FROM == NULL) // if we want to add elements to original list
    {
        P = (node *)malloc(sizeof(node));
        printf("Enter number: ");
        scanf("%d", &P->data);
        P->next = O; // added previous node to the new node next
    }
    else // if we want to create positive and negative lists
    {
        while (FROM != NULL) // looping throw the original list
        {
            P = (node *)malloc(sizeof(node));
            P->data = FROM->data;
            if (FROM->data > 0) // for positive list
            {
                P->next = POS;
                POS = P;
            }
            else // ofr negative list
            {
                P->next = NEG;
                NEG = P;
            }
            FROM = FROM->next;
        }
        P = (node *)calloc(2, sizeof(node)); // create two blocks inside p
        *(P + 0) = *POS;                     // at 0th index of p insert positve list
        *(P + 1) = *NEG;                     // at 1th index of p insert negative list
    }

    return P;
}

void display(node *NODE)
{
    while (NODE != NULL)
    {
        printf("%d ", NODE->data);
        NODE = NODE->next;
    }
}
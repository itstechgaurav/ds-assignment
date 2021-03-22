#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int data;
    struct nodetype *con; // con - connection to some node
    struct nodetype *next;
} node;

node *insert(node *);
node *create_other(node *, int);
void display(node *, int);

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
            O = insert(O);
        if (ch == 2)
        {
            P = create_other(O, 1); // create positive - 1 if positive
            N = create_other(O, 0); // create negative - 0 if negative
            printf("Original List: ");
            display(O, 0); // display the orginal node n->data
            printf("\nPositive List: ");
            display(P, 1); // display the node->con->data
            printf("\nNegitive List: ");
            display(N, 1); // display the node->con->data
        }
    }
    return 0;
}

node *insert(node *O)
{
    node *P = malloc(sizeof(node));
    printf("Enter number: ");
    scanf("%d", &P->data);

    P->next = O;
    return P;
}

node *create_other(node *O, int ch)
{
    node *P = NULL;
    while (O != NULL)
    {
        if (ch == 1 ? O->data >= 0 : O->data < 0)
        {
            node *T = malloc(sizeof(node));
            T->next = P;
            T->con = O;
            P = T;
        }
        O = O->next;
    }
    return P;
}

void display(node *NODE, int ch)
{
    while (NODE != NULL)
    {
        printf("%d ", ch ? NODE->con->data : NODE->data);
        NODE = NODE->next;
    }
}
#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
  int data;
  struct nodetype *next;
} node;

node *insert(node *);
node *delete (node *);
void display(node *);

int main()
{
  node *R = NULL;
  int ch = 1;

  while (ch >= 1 && ch <= 3)
  {
    printf("\n1: insert\n2: delete\n3: display\n[Else Exit]\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    if (ch == 1)
      R = insert(R);
    if (ch == 2)
      R = delete (R);
    if (ch == 3)
      display(R);
  }
}

node *insert(node *R) // inserting node and getting back the new last node
{
  node *P = malloc(sizeof(node));
  printf("Enter element: ");
  scanf("%d", &P->data);

  if (R == NULL) // if first node
  {
    R = P;
    R->next = R;
  }
  else // if first node already exists
  {
    P->next = R->next; // assigning first node
    R->next = P;       // assigning last node new last node address
    R = P;             // moving pointer R to new last node
  }

  return R;
}

node *delete (node *R) // remove last node and getting back the new last node
{
  if (R == NULL) // if no we don't have any node in the list
  {
    printf("List is empty");
    return NULL;
  }
  else if (R == R->next) // checking if it is the first node or not
  {
    printf("%d is deleted", R->data);
    free(R);     // remove the first node
    return NULL; // return null because no node left
  }
  else
  {
    printf("%d is delete", R->next->data);
    node *F = R->next; // first element of the list
    R->next = F->next; // assigning last(R)->next to the second(first->next)
    free(F);
    return R;
  }
}

void display(node *R) // just printing stuffs
{
  node *F;
  if (R == NULL)
    printf("Circular List is empty");
  else
  {
    F = R->next;
    do
    {
      printf("%d ", F->data);
      F = F->next;
    } while (F != R->next);
  }
}

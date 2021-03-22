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
  node *L = NULL, *R = NULL;
  int ch = 1;

  while (ch >= 1 && ch <= 3)
  {
    printf("\n1: insert\n2: delete\n3: display\n[Else Exit]\n");
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
      L = delete (L);
      if (L == NULL)
        R = NULL;
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

node *delete (node *L)
{
  if (L == NULL)
  {
    printf("linked list is empty");
    return L;
  }
  else
  {
    node *T = L;
    L = L->next;
    printf("%d is deleted", T->data);
    free(T);
    return L;
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
#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
  int data;
  struct nodetype *next;
} node;

node *insert(node *);
node *reverse(node *);
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
      R = reverse(L);
      L = R->next;
      R->next = NULL;
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

node *reverse(node *L)
{
  node *arr[100], *T;
  int n = 0;
  while (L != NULL)
  {
    arr[n] = L;
    L = L->next;
    n++;
  }
  while (n >= 0)
  {
    if (L == NULL)
    {
      L = arr[n];
      T = L;
    }
    else
    {
      L->next = arr[n];
      L = L->next;
    }
    n--;
  }
  L->next = T; // now L will be the last node and it's next will be the first node which we will remove in main function
  return L;
}

void display(node *L)
{
  while (L != NULL)
  {
    printf("%d ", L->data);
    L = L->next;
  }
}
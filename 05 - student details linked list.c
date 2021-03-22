#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
  int roll;
  char name[20], grade;
  struct nodetype *next;
} node;

node *insert(node *);
void delete (node **, node **);
void display(node *);
void print_details(node *);

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
      delete (&L, &R);
    }
    if (ch == 3)
      display(L);
  }
  return 0;
}

node *insert(node *R)
{
  // char name[20];
  node *P = malloc(sizeof(node));
  printf("Enter roll no: ");
  scanf("%d", &P->roll);
  printf("Enter name: ");
  scanf("%s", P->name);
  fflush(stdin);
  printf("Enter grade: ");
  scanf("%c", &P->grade);

  // now let's add node

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

void delete (node **L, node **R)
{
  int roll;
  printf("Enter the roll no you want to delete: ");
  scanf("%d", &roll);

  node *T = (*L);
  node *P = NULL;
  while (T != NULL && T->roll != roll)
  {
    P = T;       // added the prevoius node
    T = T->next; // moved to the next node
  }

  // found what to delete

  if (T == NULL)
  {
    printf("No record found with roll no = %d", roll);
  }
  else if ((*L) == T && T == (*R)) // if there is only one node and user wanted to delete it
  {
    (*L) = (*R) = NULL;
  }
  else if (T == (*L)) // if it is only the left node
  {
    (*L) = (*L)->next; // moved the left cursor to the next
  }
  else if (T == (*R)) // if it is only the right node
  {
    P->next = NULL;
    (*R) = P; // moved the right cursor one step back
  }
  else // if the node in the middle
  {
    P->next = T->next; // connected the prev->next to the current->next
  }

  if (T != NULL)
  {
    printf("Removed Record");
    print_details(T);
    free(T); // deleted the current node if it is not null
  }
}

void print_details(node *N)
{
  printf("\n\n***********************************\n");
  printf("Roll No: %d\n", N->roll);
  printf("Name: %s\n", N->name);
  printf("Grade: %c", N->grade);
  printf("\n***********************************\n\n");
}

void display(node *L) // just printing stuffs
{
  if (L == NULL)
    printf("Circular List is empty");
  else
  {
    while (L != NULL)
    {
      print_details(L);
      L = L->next;
    }
  }
}

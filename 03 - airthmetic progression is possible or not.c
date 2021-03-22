#include <stdio.h>
#include <stdlib.h>

void sort(int[], int); // using insertion sort;
int is_ap(int[], int);

int main()
{
  int elements[10], n, i = 0;
  printf("Enter total elements: ");
  scanf("%d", &n);
  printf("Enter %d elements: ", n);
  while (i < n)
    scanf("%d", &elements[i++]);

  if (is_ap(elements, n))
  {
    printf("AP is possible");
  }
  else
    printf("AP is not possible");
  return 0;
}

void sort(int elements[], int n)
{
  int i;
  int tmp, pos;
  for (i = 1; i < n; i++)
  {
    tmp = elements[i];
    pos = i - 1;

    while (pos >= 0 && tmp < elements[pos])
    {
      elements[pos + 1] = elements[pos];
      pos--;
    }
    elements[pos + 1] = tmp;
  }
}

int is_ap(int elements[], int n)
{
  int i;
  int is = 1;
  sort(elements, n); // first sort the elements

  // now it's time to check if the diffrence is same or not

  for (i = 1; i < n; i++)
  {
    if (elements[i] - elements[i - 1] != elements[1] - elements[0])
    {
      is = 0;
      break;
    }
  }

  return is; // 0 - not ap, 1 - ap is possible
}
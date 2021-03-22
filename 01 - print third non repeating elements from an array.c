#include <stdio.h>
#include <stdlib.h>

int get_third_no_repeating_element(int[], int);

int main()
{
  int elements[] = {1, 2, 3, 4, 5, 2, 4, 5, 7, 6, 8, 1};
  int n = 12;
  int count = get_third_no_repeating_element(elements, n);
  printf("Non Repeating Elements: %d\n", count);
  return 0;
}

int get_third_no_repeating_element(int elements[], int n)
{
  int i, j;
  int repeation_count = 0;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (elements[i] == elements[j] && i != j)
      {
        break;
      }
      else if (j == n - 1)
      {
        repeation_count++;
      }
    }
    if (repeation_count == 3)
    {
      repeation_count = elements[i];
      break;
    }
  }

  return repeation_count;
}
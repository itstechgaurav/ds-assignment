#include <stdio.h>
#include <stdlib.h>

int get_third_no_repeating_element(int[], int);

int main()
{
  int elements[] = {1, 2, 3, 4, 5, 2, 4, 5, 7, 6, 8, 1};
  int n = 12;
  int count = get_third_no_repeating_element(elements, n);
  printf("Non Repeating Element: %d\n", count);
  return 0;
}

int get_third_no_repeating_element(int elements[], int n)
{
  int i, j;
  int repeation_count = 0; // will store the repeation count upto 3

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (elements[i] == elements[j] && i != j)
      {
        // checking if we found a duplicate element and also it is not equal to it's self
        break; // if so then exit from the current iteration and move to the next iteration
      }
      else if (j == n - 1)
      {
        // and if loop is at the last element that means we don't have any duplicate of current element
        // then repeat the repeation_count by 1
        repeation_count++;
      }
    }
    if (repeation_count == 3)
    {
      // at last check if repeation_count == 3 that means we found first three element and the current element
      // is the non duplicate third element then exit from the loop
      repeation_count = elements[i]; // this time it will store the element it's self
      break;
    }
  }

  return repeation_count; // now we got the third non repeating element now return it
}
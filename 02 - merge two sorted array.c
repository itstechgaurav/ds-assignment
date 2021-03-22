#include <stdio.h>

void merge(int[], int[], int, int);
void print(int[], int n);

int main()
{
    int arr[10] = {5, 7, 9};
    int brr[10] = {4, 6, 8};
    int an = 3, bn = 3;
    printf("First Array: ");
    print(arr, an);
    printf(" Second Array: ");
    print(brr, bn);
    merge(arr, brr, an, bn);
    printf("Merged Array: ");
    print(arr, an + bn);
    return 0;
}

void merge(int arr[], int brr[], int an, int bn)
{
    int i = 0, j = 0, k, st = 0;
    for (i = 0; i < bn; i++)
    {
        for (j = st; j < an; j++)
        {
            if (brr[i] < arr[j])
            {
                k = an;
                while (k > j)
                {
                    arr[k] = arr[k - 1];
                    k--;
                }
                an++;
                st = j + 1;
                arr[j] = brr[i];
                break;
            }
        }
    }
}

void print(int arr[], int n)
{
    int i = 0;
    while (i < n)
        printf("%d ", arr[i++]);
    printf("\n");
}
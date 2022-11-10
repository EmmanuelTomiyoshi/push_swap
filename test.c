#include <stdio.h>

void    swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int leftmost, int rightmost)
{
    int pivot;
    int i;
    int j;

    pivot = array[rightmost];
    i = (leftmost - 1);
    j = leftmost;
    while (j < rightmost)
    {
        if (array[j] <= pivot)
        {
            i++;
            // printf("\ndentro: array[i] = %d | array[j] = %d\n",
            // i, array[i], j, array[j]);
            swap(&array[i], &array[j]);
        }
        j++;
    }
    swap(&array[i + 1], &array[rightmost]);
    // printf("\nfora: array[i + 1] = %d | array[%d] = %d\n",
    // i, array[i + 1], rightmost, array[rightmost]);

    return (i + 1);
}

//low = leftmost | high = rightmost
void    quickSort(int array[], int leftmost, int rightmost)
{
    int pi;

    // static int p = 0;

    // printf("\np: %d\n", p);
    // p++;
    // if (p == 1)
    //     printf("low: %d | high: %d\n", leftmost, rightmost);
    if (leftmost < rightmost)
    {
        pi = partition(array, leftmost, rightmost);

        quickSort(array, leftmost, pi - 1);
        quickSort(array, pi + 1, rightmost);
    }
}

void    printArray(int array[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("%d  ", array[i]);
        i++;
    }
    printf("\n");
}

int main(void)
{
    int data[] = {2, 8, 1, 3, -2, 4, -5, 6, 7};
    int n = sizeof(data) / sizeof(data[0]);
    
    printArray(data, n);
    quickSort(data, 0, n - 1);
    printArray(data, n);
}

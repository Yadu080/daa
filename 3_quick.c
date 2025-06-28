#include <stdio.h>
#include <stdlib.h>

int count;

int partition(int a[10], int low, int high) {
    int i = low + 1;
    int j = high;
    int pivot = a[low];
    int temp;

    while (1) {
        while ((i <= high) && (pivot >= a[i])) {
            i++;
            count++;
        }
        count++;

        while ((j >= low) && (pivot < a[j])) {
            j--;
            count++;
        }
        count++;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

void quicksort(int a[10], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int main() {
    int a[10];
    int i, n;

    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("\nSorted elements:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    printf("\nNumber of comparisons: %d\n", count);

    return 0;
}

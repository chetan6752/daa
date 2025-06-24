#include <stdio.h>
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pivot = a[high], i = low - 1;
        for (int j = low; j < high; j++)
            if (a[j] < pivot)
                { int temp = a[++i]; a[i] = a[j]; a[j] = temp; }
        int temp = a[i+1]; a[i+1] = a[high]; a[high] = temp;
        int pi = i + 1;
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
int main() {
    int a[] = {10, 7, 8, 9, 1, 5, 4, 3, 10}, n = sizeof(a)/sizeof(a[0]);
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

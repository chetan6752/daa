//[4] KNAPSACK USING GREEDY METHOD

#include <stdio.h>
struct Item { int w, v; };

void sort(struct Item a[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if ((float)a[j].v/a[j].w < (float)a[j+1].v/a[j+1].w) {
                struct Item temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
            }
}
float knapsack(struct Item a[], int n, int cap) {
    sort(a, n);
    float val = 0;
    for (int i = 0; i < n && cap > 0; i++) {
        if (a[i].w <= cap) { val += a[i].v; cap -= a[i].w; }
        else { val += (float)a[i].v * cap / a[i].w; break; }
    }
    return val;
}
int main() {
    int n, cap;
    printf("Enter number of items: "); scanf("%d", &n);
    struct Item a[n];
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i+1);
        scanf("%d %d", &a[i].w, &a[i].v);
    }
    printf("Enter capacity: "); scanf("%d", &cap);
    printf("Max value = %.2f\n", knapsack(a, n, cap));
    return 0;
}

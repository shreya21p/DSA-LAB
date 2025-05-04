//Program to implement block tower program
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void solve() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        qsort(a, n, sizeof(int), cmp); // Sort in ascending order

        int sum = a[0]; // Start with blocks on tower 1
        for (int i = 1; i < n; i++) {
            if (a[i] > sum) {
                sum = (sum + a[i]) / 2;
            } else {
                sum = sum + a[i];
            }
        }

        printf("%d\n", sum);
    }
}

int main() {
    solve();
    return 0;
}


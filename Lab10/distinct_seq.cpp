// Program to remove the smallest prefix from a sequence so that all remaining elements are unique
#include <cstdio>
#include <set>

const int MAX_N = 200000;

int main() {
    int t, n, a[MAX_N];
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        std::set<int> uniqueSet;
        int minRemove = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (uniqueSet.count(a[i])) {
                minRemove = i + 1;
                break;
            }
            uniqueSet.insert(a[i]);
        }

        printf("%d\n", minRemove);
    }

    return 0;
}

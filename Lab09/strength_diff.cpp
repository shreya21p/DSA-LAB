//Program to find the advantage for the players
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        int max1 = -1, max2 = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] > max1) {
                max2 = max1;
                max1 = s[i];
            } else if (s[i] > max2) {
                max2 = s[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == max1) {
                cout << s[i] - max2 << " ";
            } else {
                cout << s[i] - max1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

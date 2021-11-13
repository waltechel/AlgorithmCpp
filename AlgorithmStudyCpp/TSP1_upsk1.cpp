#include <bits/stdc++.h>
using namespace std;
double a[8][8];
int b[8];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed;
    cout.precision(10);
    int T;
    cin >> T;
    while (T--) {
        double ans = 1415 * 10;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)b[i] = i;
        do {
            double sum = 0;
            for (int i = 1; i < n; i++) {
                sum += a[b[i - 1]][b[i]];
            }
            ans = min(ans, sum);
        } while (next_permutation(b, b + n));
        cout << ans << '\n';
    }
}
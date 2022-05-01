#include <bits/stdc++.h>
using namespace std;
long long r[201], p[201];
long long gcd(long long a, long long b) { for (; b; a %= b, swap(a, b)); return a; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        long long g = 0;
        for (int i = 1; i <= n; i++) {
            cin >> r[i];
            g = gcd(g, r[i]);
        }
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        long long MAX = 1;
        for (int i = 1; i <= n; i++) {
            r[i] /= g;
            if (r[i] < p[i]) {
                long long div = p[i] / r[i];
                if (p[i] % r[i])div++;
                MAX = max(MAX, div);
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            r[i] *= MAX;
            cout << r[i] - p[i] << ' ';
        }
        cout << '\n';
    }
}
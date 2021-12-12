#include <bits/stdc++.h>
using namespace std;
long long d[101];
const long long mod = 1000000007;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= 100; i++) {
        d[i] = d[i - 1] + d[i - 2];
        d[i] %= mod;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}
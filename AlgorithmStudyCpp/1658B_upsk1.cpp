#include <bits/stdc++.h>
using namespace std;
long long fact[1001];
const long long mod = 998244353;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fact[1] = 1;
    for (long long i = 2; i <= 1000; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 2)cout << "0\n";
        else {
            long long ans = fact[n / 2] * fact[n / 2];
            ans %= mod;
            cout << ans << '\n';
        }
    }


}
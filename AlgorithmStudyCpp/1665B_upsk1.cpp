#include <bits/stdc++.h>
using namespace std;
long long a[100001];
map<long long, long long> Map;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        Map.clear();
        int n;
        cin >> n;
        long long MAX = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            Map[a[i]]++;
            MAX = max(MAX, Map[a[i]]);
        }
        long long rest = n - MAX;
        long long ans = 0;
        while (rest) {
            ans++;
            long long MIN = min(rest, MAX);
            rest -= MIN;
            MAX *= 2LL;
            ans += MIN;
        }
        cout << ans << '\n';

    }

}
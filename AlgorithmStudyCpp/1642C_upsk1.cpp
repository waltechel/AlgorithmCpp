#include <bits/stdc++.h>
using namespace std;
long long a[200001];
multiset<long long> Set;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        Set.clear();
        long long n, x;
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            Set.insert(a[i]);
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            auto it = Set.find(a[i]);
            if (it == Set.end())continue;
            auto it2 = Set.find(a[i] * x);
            if (it2 == Set.end())ans++;
            else Set.erase(it2);
            Set.erase(it);
        }

        cout << ans << '\n';

    }
}
#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed;
    cout.precision(10);
    int T;
    cin >> T;
    while (T--) {
        long long n, m;
        cin >> n >> m;
        long long now = (m * 100LL) / n;
        long long l = 0, r = 2000000000LL;
        long long tn = n + r, tm = m + r;
        long long tnow = (tm * 100LL) / tn;
        if (now == tnow) {
            cout << -1 << '\n';
            continue;
        }
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long n2 = n + mid, m2 = m + mid;
            long long now2 = (m2 * 100LL) / n2;
            if (now < now2)r = mid - 1;
            else l = mid + 1;
        }
        cout << l << '\n';
    }


}
#include <bits/stdc++.h>
using namespace std;
int d[20000001];
pair<int, int> a[21];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            a[i].first /= 100;
        }
        m /= 100;
        for (int i = 1; i <= m; i++) {
            d[i] = 0;
            for (int j = 0; j < n; j++) {
                if (i >= a[j].first) {
                    d[i] = max(d[i], d[i - a[j].first] + a[j].second);
                }
            }
        }
        cout << d[m] << '\n';
    }

}
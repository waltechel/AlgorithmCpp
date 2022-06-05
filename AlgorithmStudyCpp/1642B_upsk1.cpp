#include <bits/stdc++.h>
using namespace std;
map<int, int> Map;
int a[300001];
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        Map.clear();
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (Map[a[i]] == 0)ans++;
            Map[a[i]]++;
        }
        int dif = n - ans;
        for (int i = 0; i < ans; i++)cout << ans << ' ';
        for (int i = 1; i <= dif; i++)cout << ans + i << ' ';
        cout << '\n';
    }
}
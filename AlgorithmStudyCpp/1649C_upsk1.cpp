#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> v[100001];
bool cmp1(pair<long long, long long> p1, pair<long long, long long> p2) {
    return p1.first < p2.first;
}
bool cmp2(pair<long long, long long> p1, pair<long long, long long> p2) {
    return p1.second < p2.second;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int t;
            cin >> t;
            v[t].push_back({ i,j });
        }
    }
    long long ans = 0;
    for (int i = 1; i <= 100000; i++) {
        sort(v[i].begin(), v[i].end(), cmp1);
        long long sum = 0;
        for (long long j = 0; j < v[i].size(); j++) {
            ans += j * v[i][j].first;
            ans -= sum;
            sum += v[i][j].first;
        }
    }
    for (int i = 1; i <= 100000; i++) {
        sort(v[i].begin(), v[i].end(), cmp2);
        long long sum = 0;
        for (long long j = 0; j < v[i].size(); j++) {
            ans += j * v[i][j].second;
            ans -= sum;
            sum += v[i][j].second;
        }
    }
    cout << ans << '\n';

}
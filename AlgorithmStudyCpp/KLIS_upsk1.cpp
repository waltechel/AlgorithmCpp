#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[502], len[502], cnt[502];
const long long MAX = 2000000000 + 1;
vector<int> ans;
int lis(int start) {
    int& ret = len[start + 1];
    if (ret != -1)return ret;
    ret = 1;
    for (int i = start + 1; i <= n; i++) {
        if (a[start] < a[i]) {
            ret = max(ret, lis(i) + 1);
        }
    }
    return ret;
}
int count(int start) {
    if (lis(start) == 1)return 1;
    int& ret = cnt[start + 1];
    if (ret != -1)return ret;
    ret = 0;
    for (int i = start + 1; i <= n; i++) {
        if (a[start] < a[i] && lis(start) == lis(i) + 1) {
            ret = min(MAX, (long long)ret + count(i));
        }
    }
    return ret;
}
void trace(int start, int skip) {
    if (start)ans.push_back(a[start]);
    vector<pair<int, int>> v;
    for (int i = start + 1; i <= n; i++) {
        if (a[start] < a[i] && lis(start) == lis(i) + 1) {
            v.push_back({ a[i],i });
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (count(v[i].second) <= skip)skip -= count(v[i].second);
        else {
            trace(v[i].second, skip);
            break;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        memset(len, -1, sizeof(len));
        memset(cnt, -1, sizeof(cnt));
        for (int i = 1; i <= n; i++)cin >> a[i];
        cout << lis(0) - 1 << '\n';
        ans.clear();
        trace(0, k - 1);
        for (auto kk : ans)cout << kk << ' ';
        cout << '\n';
    }

}
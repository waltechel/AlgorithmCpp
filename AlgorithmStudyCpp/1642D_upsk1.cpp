#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        deque<int> a(n);
        map<int, int> Map;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            Map[a[i]]++;
        }
        bool flag = true;
        for (auto kk : Map) {
            if (kk.second % 2) {
                flag = false;
                break;
            }
        }
        if (flag == false) {
            cout << "-1\n";
            continue;
        }
        vector<pair<int, int>> ans;
        vector<int> ans_p;
        int res = 0;
        while (a.size()) {
            int idx = 1;
            while (a.front() != a[idx])idx++;
            ans_p.push_back(idx * 2);
            vector<int> v;
            for (int i = 1; i < idx; i++)v.push_back(a[i]);
            for (int i = 0; i <= idx; i++)a.pop_front();
            int cnt = 0;
            for (auto kk : v) {
                ans.push_back({ res + idx + 1 + cnt,kk });
                cnt++;
            }
            for (auto kk : v) a.push_front(kk);
            res += idx * 2;
        }
        cout << ans.size() << '\n';
        for (auto kk : ans)cout << kk.first << ' ' << kk.second << '\n';
        cout << ans_p.size() << '\n';
        for (auto kk : ans_p)cout << kk << ' ';
        cout << '\n';
    }


}
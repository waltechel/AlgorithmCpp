#pragma GCC optimize("O2")
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
unsigned long popcount(unsigned long long n) {
    unsigned long cnt = 0;
    for(unsigned long i = 0; i < 64; i++) {
        cnt += ((n >> i) & 1);
    } return cnt;
}
unsigned long minimum(vector<vector<int>> const &v, unsigned long long selected, int const n, int const m, int cnt, unsigned long current_min) {
    auto const popcnt = popcount(selected);
    if(popcnt >= current_min) return current_min;
    if(cnt == n) return popcnt;
    unsigned long min = current_min;
    bool flag = false;
    for(auto now : v[cnt]) {
        if(popcnt >= min) break;
        auto const bit = ((unsigned long long)(1) << (unsigned long long)(now));
        if(!(selected & bit)) {
            selected |= bit;
            auto const x = minimum(v, selected, n, m, cnt + 1, min);
            if(min > x) min = x;
            selected ^= bit;
        }
        else if(!flag) {
            flag = true;
            auto const x = minimum(v, selected, n, m, cnt + 1, min);
            if(min > x) min = x;
        }
    }
    return min;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, m; cin >> n >> m;
        vector<string> names; names.reserve(n);
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            names.emplace_back(move(s));
        } sort(names.begin(), names.end());
        vector<vector<int>> v(n, vector<int>{});
        for(int i = 0; i < m; i++) {
            int k; cin >> k;
            while(k--) {
                string s; cin >> s;
                auto x = lower_bound(names.begin(), names.end(), s) - names.begin();
                v[x].push_back(i);
            }
        } sort(v.begin(), v.end(), [](vector<int> const &a, vector<int> const &b) {
            return a.size() < b.size();
        });
        unsigned long long selected = 0;
        cout << minimum(v, selected, n, m, 0, 1000) << '\n';
    }
}
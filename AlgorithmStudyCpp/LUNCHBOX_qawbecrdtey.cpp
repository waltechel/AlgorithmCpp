#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        auto a = new pair<int, int>[n];
        int wave = 0;
        for(int i = 0; i < n; i++) { cin >> a[i].first; wave += a[i].first; }
        for(int i = 0; i < n; i++) cin >> a[i].second;
        sort(a, a + n, [](pair<int, int> const &a, pair<int, int> const &b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        });
        int max = 0;
        for(int i = 0; i < n; i++) {
            if(max < wave + a[i].second) max = wave + a[i].second;
            wave -= a[i].first;
        }
        cout << max << '\n';
        delete[] a;
    }
}
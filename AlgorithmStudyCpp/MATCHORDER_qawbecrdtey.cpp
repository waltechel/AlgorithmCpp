#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        auto a = new int[n];
        auto b = new int[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        sort(a, a + n, [](int a, int b) { return a > b; });
        sort(b, b + n);
        int cnt = 0, idx = n - 1;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++) {
            while(idx >= 0 && b[idx] >= a[i]) pq.push(-b[idx--]);
            if(!pq.empty()) {
                pq.pop(); cnt++;
            }
        }
        cout << cnt << '\n';
        delete[] a;
        delete[] b;
    }
}
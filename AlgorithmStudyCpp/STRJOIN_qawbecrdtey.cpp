#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++) {
            int x; cin >> x; pq.push(-x);
        }
        int sum = 0;
        while(pq.size() > 1) {
            int const x = pq.top(); pq.pop();
            int const y = pq.top(); pq.pop();
            int const z = x + y;
            sum -= z;
            pq.push(z);
        }
        cout << sum << '\n';
    }
}
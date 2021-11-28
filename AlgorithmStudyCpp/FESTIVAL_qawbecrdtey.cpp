#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin >> t;
    while(t--) {
        int n, l;
        cin >> n >> l;

        // prefix sum
        auto a = new int[n + 1];
        a[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }

        double ans = 1e10;
        for(int i = 0; i < n; i++) {
            for(int j = i + l; j <= n; j++) {
                if(ans > (double)(a[j] - a[i]) / (j - i)) {
                    ans = (double)(a[j] - a[i]) / (j - i);
                }
            }
        }
        cout << ans << '\n';

        delete[] a;
    }
}
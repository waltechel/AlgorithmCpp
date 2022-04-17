#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed;
    cout.precision(10);
    int T;
    cin >> T;
    while (T--) {
        double origin, P;
        int M;
        cin >> origin >> M >> P;
        double l = 0, r = origin + (origin * ((P / 12.0) / 100.0));
        for (int i = 0; i < 1000; i++) {
            double mid = (l + r) / 2.0;
            int cnt = 0;
            double o2 = origin;
            bool flag = false;
            for (int j = 0; j < M; j++) {
                o2 += (o2 * ((P / 12.0) / 100.0));
                o2 -= mid;
                if (o2 <= 0.0) {
                    flag = true;
                    break;
                }
            }
            if (flag)r = mid;
            else l = mid;
        }
        cout << l << '\n';
    }


}
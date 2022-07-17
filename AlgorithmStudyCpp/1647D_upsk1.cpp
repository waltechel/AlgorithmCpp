#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        long long x, d;
        cin >> x >> d;
        if (x % (d * d)) {
            cout << "NO\n";
            continue;
        }
        long long x2 = x, cnt = 0;
        while (x2 % d == 0) {
            x2 /= d;
            cnt++;
        }
        bool flag = false;
        for (long long i = 2; i * i <= x2; i++) {
            if (x2 % i == 0) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "YES\n";
            continue;
        }
        if (cnt == 2) {
            cout << "NO\n";
            continue;
        }
        if (d == (x2 * x2)) {
            if (cnt > 3)cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            flag = false;
            for (long long i = 2; i * i <= d; i++) {
                if (d % i == 0) {
                    flag = true;
                    break;
                }
            }
            if (flag)cout << "YES\n";
            else cout << "NO\n";
        }
    }

}
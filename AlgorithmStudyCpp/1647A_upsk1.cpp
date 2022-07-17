#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string ans = "";
        int sum = 0;
        int idx = 0;
        while (sum < n) {
            if (idx % 2) {
                sum += 1;
                ans += '1';
            }
            else {
                if (sum + 2 > n)break;
                sum += 2;
                ans += '2';
            }
            if (sum == n)break;
            idx++;
        }

        if (sum != n)cout << "1";
        cout << ans << '\n';

    }

}
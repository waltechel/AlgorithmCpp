#include <bits/stdc++.h>
using namespace std;
string s[101];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)cin >> s[i];
        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int cnt = 0;
                for (int o = i; o <= i + 1; o++) {
                    for (int p = j; p <= j + 1; p++) {
                        if (s[o][p] == '1')cnt++;
                    }
                }
                if (cnt == 3) {
                    flag = false;
                    break;
                }
            }
            if (flag == false)break;
        }
        if (flag)cout << "YES\n";
        else cout << "NO\n";

    }

}
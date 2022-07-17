#include <bits/stdc++.h>
using namespace std;
bool cnt[1000001];
int sum[1000001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        for (int i = 1; i <= c; i++)cnt[i] = false;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            cnt[t] = true;
        }
        if (cnt[1] == false) {
            cout << "No\n";
            continue;
        }
        bool flag = true;
        for (int i = 1; i <= c; i++) {
            sum[i] = sum[i - 1] + cnt[i];
        }
        for (int i = 1; i <= c; i++) {
            if (cnt[i]) {
                int num = 2;
                while (true) {
                    int l = i * num, r = i * (num + 1) - 1;
                    if (l > c)break;
                    if (r > c)r = c;
                    int tnum = sum[r] - sum[l - 1];
                    if (tnum) {
                        if (cnt[num] == false) {
                            flag = false;
                            break;
                        }
                    }
                    num++;
                }
                if (flag == false)break;
            }
        }
        if (flag)cout << "Yes\n";
        else cout << "No\n";
    }
}
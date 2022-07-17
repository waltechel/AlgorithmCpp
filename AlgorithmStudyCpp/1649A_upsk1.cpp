    #include <bits/stdc++.h>
    using namespace std;
    int a[101];
    int main() {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
     
        int T;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            for (int i = 1; i <= n; i++)cin >> a[i];
            int ans = 0;
            int l = -1, r = n;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 0) {
                    l = i;
                    break;
                }
            }
            if (l != -1) {
                for (int i = n; i > 0; i--) {
                    if (a[i] == 1)r = i;
                    else break;
                }
                ans = (r - l) + 1;
            }
            cout << ans << '\n';
        }
    }
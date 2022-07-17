#include <bits/stdc++.h>
using namespace std;
string s;
queue<int> q;
int cnt[200001];
int Swap(int x) {
    if (s[x] == '1')s[x] = '0';
    else s[x] = '1';
    return s[x];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        while (!q.empty())q.pop();
        int n, k;
        cin >> n >> k >> s;
        for (int i = 0; i < n; i++)cnt[i] = 0;
        if (k % 2) {
            for (int i = 0; i < n; i++) {
                if (s[i] == '1')q.push(i);
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                if (s[i] == '0')q.push(i);
            }
        }
        while (k > 1) {
            if (q.size() == 0)break;
            if (q.size() == 1) {
                int x = q.front();
                q.pop();
                if (x != (n - 1)) {
                    Swap(x); Swap(n - 1);
                    cnt[x]++; cnt[n - 1]++;
                    k -= 2;
                }
                break;
            }
            else {
                int x = q.front(); q.pop();
                int y = q.front(); q.pop();
                Swap(x); Swap(y);
                cnt[x]++; cnt[y]++;
                k -= 2;
            }
        }
        int MIN = n - 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                MIN = i;
                break;
            }
        }
        cnt[MIN] += k;
        if (k % 2) {
            for (int i = 0; i < n; i++) {
                if (i == MIN)continue;
                Swap(i);
            }
        }
        cout << s << '\n';
        for (int i = 0; i < n; i++)cout << cnt[i] << ' ';
        cout << '\n';
    }
}
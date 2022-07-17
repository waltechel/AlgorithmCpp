#include <bits/stdc++.h>
using namespace std;
string s[101];
struct A {
    int x1, y1, x2, y2;
};
vector<A> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        v.clear();
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)cin >> s[i];
        if (s[0][0] == '1') {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j > 0; j--) {
                if (i == 0 && j == 0)continue;
                if (s[i][j] == '1') {
                    v.push_back({ i + 1,j,i + 1,j + 1 });
                }
            }
        }
        for (int i = n - 1; i > 0; i--) {
            if (s[i][0] == '1') {
                v.push_back({ i,1,i + 1,1 });
            }
        }
        cout << v.size() << '\n';
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].x1 << ' ' << v[i].y1 << ' ' << v[i].x2 << ' ' << v[i].y2 << '\n';
        }
    }

}
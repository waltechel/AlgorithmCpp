#include <bits/stdc++.h>
using namespace std;
double adj[15][15];
double d[1 << 15][15];
bool check[1 << 15][15];
int pow2[15];
int n;
int full;
const double MAX = 3e6;
double solve(int state, int x) {
    //cout << state << ' ' << x << '\n';
    if (state == full) {
        return 0.0;
    }
    if (check[state][x])return d[state][x];
    check[state][x] = true;
    d[state][x] = MAX;
    for (int i = 0; i < n; i++) {
        if (state & pow2[i])continue;
        if (adj[x][i] < 0.00000000001)continue;
        d[state][x] = min(d[state][x], solve(state | pow2[i], i) + adj[x][i]);
    }
    return d[state][x];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed;
    cout.precision(10);
    pow2[0] = 1;
    for (int i = 1; i < 15; i++)pow2[i] = pow2[i - 1] * 2;
    int T;
    cin >> T;
    while (T--) {
        memset(check, false, sizeof(check));
        cin >> n;
        full = (1 << n) - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> adj[i][j];
            }
        }
        double ans = MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, solve(pow2[i], i));
        }
        cout << ans << '\n';
    }

}
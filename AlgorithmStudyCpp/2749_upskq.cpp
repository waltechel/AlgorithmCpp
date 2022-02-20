#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000;
vector<vector<long long>> mul(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> c(2, vector<long long>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}
long long go(vector<vector<long long>> x, long long y) {
    vector<vector<long long>> ret(2, vector<long long>(2));
    ret[0][0] = ret[1][1] = 1;
    while (y) {
        if (y % 2)ret = mul(ret, x);
        x = mul(x, x);
        y /= 2;
    }

    return ret[1][0];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n;
    cin >> n;
    vector<vector<long long>> x(2, vector<long long>(2, 1));
    x[1][1] = 0;
    cout << go(x, n);
}
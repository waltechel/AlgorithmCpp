#include <bits/stdc++.h> 
using namespace std;
int n, k;
int R[1001], C[1001];
bool decision(double x) {
    vector<double> v;
    for (int i = 0; i < n; i++)v.push_back(x * C[i] - R[i]);
    sort(v.begin(), v.end());
    double sum = 0;
    for (int i = n - k; i < n; i++)sum += v[i];
    return sum >= 0.0;
}
double optimize() {
    double l = -1e-9, r = 1;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        if (decision(mid))r = mid;
        else l = mid;
    }
    return r;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed;
    cout.precision(10);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> R[i] >> C[i];
        }
        cout << optimize() << '\n';
    }
}
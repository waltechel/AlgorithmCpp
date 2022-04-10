#include <bits/stdc++.h> 
using namespace std;
long long L[5001], M[5001], G[5001];
long long n, k;
bool decision(long long x) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        if (x >= L[i] - M[i]) {
            long long cur = min(x, L[i]);
            cnt += (cur - (L[i] - M[i])) / G[i] + 1;
        }
    }
    return cnt >= k;
}

int optimize() {
    int l = 0, r = 8030000;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (decision(mid))r = mid - 1;
        else l = mid + 1;
    }
    return l;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> L[i] >> M[i] >> G[i];
        }
        cout << optimize() << '\n';
    }
}
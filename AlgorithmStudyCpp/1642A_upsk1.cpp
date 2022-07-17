#include <bits/stdc++.h>
using namespace std;
struct A {
    int x, y;
    bool operator<(const A& p)const {
        if (y == p.y)return x < p.x;
        return y > p.y;
    }
};
A a[3];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed;
    cout.precision(9);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 3; i++)cin >> a[i].x >> a[i].y;
        sort(a, a + 3);
        if (a[0].y == a[1].y) {
            if (a[0].y > a[2].y) {
                cout << (double)(abs(a[0].x - a[1].x)) << '\n';
                continue;
            }
        }
        cout << 0.0 << '\n';
    }
}
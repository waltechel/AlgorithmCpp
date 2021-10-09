#include <bits/stdc++.h>
using namespace std;
int get(int state, int index) {
    return (state >> (index * 2)) & 3;
}
int set1(int state, int index, int value) {
    return (state & ~(3 << (index * 2))) | (value << (index * 2));
}
int sgn(int x) { if (!x) return 0; return x > 0 ? 1 : -1; }
int incr(int x) { if (x < 0)return x - 1; return x + 1; }
int c[(1 << 24)];
int bidir(int discs, int begin, int end) {
    if (begin == end) return 0;
    queue<int> q;
    memset(c, 0, sizeof(c));
    q.push(begin); c[begin] = 1;
    q.push(end); c[end] = -1;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        int top[4] = { -1,-1,-1,-1 };
        for (int i = discs - 1; i >= 0; i--)top[get(here, i)] = i;
        for (int i = 0; i < 4; i++) {
            if (top[i] != -1) for (int j = 0; j < 4; j++) {
                if (i != j && (top[j] == -1 || top[j] > top[i])) {
                    int there = set1(here, top[i], j);

                    if (c[there] == 0) {
                        c[there] = incr(c[here]);
                        q.push(there);
                    }
                    else if (sgn(c[there]) != sgn(c[here]))
                        return abs(c[there]) + abs(c[here]) - 1;
                }
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int state = 0;
        for (int i = 0; i < 4; i++) {
            int x;
            cin >> x;
            for (int j = 0; j < x; j++) {
                int t;
                cin >> t;
                t--;
                state |= (i << (t * 2));
            }
        }
        cout << bidir(n, state, (1 << (n * 2)) - 1) << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
long long a[200001];
long long d[800001], lazy[800001];
int ans[200001];
void init(int node, int start, int end) {
    lazy[node] = 0;
    if (start == end) {
        d[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    d[node] = d[node * 2] + d[node * 2 + 1];
}
void lazyCheck(int node, int start, int end) {
    d[node] += lazy[node] * (end - start + 1);
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}
void lazyUpdate(int node, int start, int end, int i, int j, long long diff) {
    lazyCheck(node, start, end);
    if (start > j || end < i)return;
    if (start >= i && end <= j) {
        d[node] += diff * (end - start + 1);
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    lazyUpdate(node * 2, start, mid, i, j, diff);
    lazyUpdate(node * 2 + 1, mid + 1, end, i, j, diff);
    d[node] = d[node * 2] + d[node * 2 + 1];
}
long long query(int node, int start, int end, int i, int j) {
    lazyCheck(node, start, end);
    if (start > j || end < i)return 0;
    if (start >= i && end <= j) {
        return d[node];
    }
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, i, j) + query(node * 2 + 1, mid + 1, end, i, j);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        init(1, 1, n);
        for (int i = n; i > 0; i--) {
            int num = query(1, 1, n, i, i);
            if (num == i)ans[i] = 1;
            else ans[i] = 0;
            long long cnt = sum / i;
            if (cnt == 0)continue;
            lazyUpdate(1, 1, n, i - (cnt - 1), i, -1);
            sum -= num;
            sum -= (cnt - 1);
        }
        for (int i = 1; i <= n; i++)cout << ans[i] << ' ';
        cout << '\n';
    }

}
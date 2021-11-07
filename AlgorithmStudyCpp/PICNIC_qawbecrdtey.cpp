#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int count(vector<int> const *v, bool *visited, int n, int from, int to) {
    int cnt = 0, next = from + 1;
    visited[from] = visited[to] = true;
    while(next < n && visited[next]) next++;
    if(next == n) {
        visited[from] = visited[to] = false;
        return 1;
    }
    for(int now : v[next])
        if(!visited[now])
            cnt += count(v, visited, n, next, now);
    visited[from] = visited[to] = false;
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        auto v = new vector<int>[n];
        while(m--) {
            int x, y;
            cin >> x >> y;
            if(x > y) swap(x, y);
            v[x].push_back(y);
        }
        auto visited = new bool[n]();
        int cnt = 0;
        for(int now : v[0]) cnt += count(v, visited, n, 0, now);
        cout << cnt << '\n';
        delete[] visited;
        delete[] v;
    }
}
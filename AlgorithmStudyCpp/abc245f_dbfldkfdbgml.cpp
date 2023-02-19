#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

vector<int>graph[200001];
int finished[200001];
int ordering[200001];
int cycled[200001];
int order;
vector<vector<int>> scc;
stack<int> stk;

int dfs(int now) {
    ordering[now] = order++;
    stk.push(now);

    int ret = ordering[now];
    for (int next : graph[now]) {
        if (ordering[next] == 0) {
            ret = min(ret, dfs(next));
        }
        if (finished[next] == 0) {
            ret = min(ret, ordering[next]);
        }
    }

    if (ret == ordering[now]) {
        vector<int> list;
        while (true) {
            int n = stk.top();
            stk.pop();
            list.push_back(n);
            finished[n] = 1;
            if (now == n) {
                break;
            }
        }
        scc.push_back(list);
    }

    return ret;
}

bool dfs2(int now, int prev) {
    if (cycled[now]) {
        return true;
    }
    bool ret = false;
    for (int next : graph[now]) {
        if (next == prev) {
            continue;
        }
        if (cycled[next] == false) {
            ret = max(ret, dfs2(next, now));
            if (ret == true) {
                break;
            }
        }
        if (cycled[next]) {
            return cycled[now] = true;
        }
    }
    return cycled[now] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    // scc를 구성했다.
    order = 1;
    for (int i = 1; i <= N; i++) {
        if (ordering[i] == 0) {
            dfs(i);
        }
    }

    for (vector<int> list : scc) {
        if (list.size() > 1) {
            for (int v : list) {
                cycled[v] = true;
            }
        }
    }

    /*for (int i = 1; i <= N; i++) {
        if (cycled[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";*/

    for (int i = 1; i <= N; i++) {
        if (cycled[i] == false) {
            dfs2(i, 0);
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (cycled[i]) {
            answer++;
        }
    }
    cout << answer << "";

    return 0;
}
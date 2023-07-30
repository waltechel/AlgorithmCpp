#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<unordered_set>
#include<regex>
#include<bitset>

using namespace std;

vector<vector<int>> DIRECTIONS = { {-1, 0}, {1, 0}, {0, -1},{0, 1} };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int T, N, M;
    cin >> T;
    for(int test = 0 ; test < T ; test++) {
        
        int A[501] = { 0 };
        bool graph[501][501] = { false };
        int indegree[501] = { 0 };

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                graph[A[i]][A[j]] = true;
                indegree[A[j]]++;
            }
        }

        cin >> M;
        for (int i = 0; i < M; i++) {
            int from, to;
            cin >> from >> to;
            // 그 대신에 작년에 비해서 상대적인 순위가 바뀐 팀의 목록만 발표하려고 한다.
            if (graph[from][to]) { // from이 to보다 순위가 높은 경우 to가 순위가 높도록 변경
                indegree[from]++;
                indegree[to]--;
            } else {
                indegree[from]--;
                indegree[to]++;
            }
            graph[from][to] = !graph[from][to];
            graph[to][from] = !graph[to][from];
        }
        
        queue<int> que;
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<int> answer;
        while(que.size()) {
            int now = que.front();
            que.pop();
            answer.push_back(now);
            indegree[now]--;
            for (int next = 1; next <= N; next++) {
                if (graph[now][next]) {
                    indegree[next]--;
                    if (indegree[next] == 0) {
                        que.push(next);
                    }
                }
            }
        }

        if (answer.size() == N) {
            for (int i = 0; i < N; i++) {
                cout << answer[i] << ' ';
            }
            cout << "\n";
        } else {
            cout << "IMPOSSIBLE" << "\n";
        }
    }

    return 0;

}
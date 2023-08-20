#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <regex>
#include <chrono> // 추가

using namespace std;
using namespace chrono; // 추가

vector<vector<int>> DIRECTIONS = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

/*
    희한하게 이분탐색을 안 하면 4초 정도 나온다
    이분탐색을 하면 시간이 줄어든다.
*/

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    auto start_time = high_resolution_clock::now(); // 시작 시간 측정
    int answer = -1;
    for (int diff = 128; diff > 0; diff /= 2) {
        answer += diff;
        vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(N, vector<bool>(201, false)));

        queue<int*> que;
        int* temp = new int[4];
        temp[0] = 0;
        temp[1] = 0;
        temp[2] = graph[0][0]; // 최솟값
        temp[3] = graph[0][0]; // 최댓값
        que.push(temp);

        while (!que.empty()) {
            int* now = que.front();
            que.pop();
            int row = now[0];
            int col = now[1];
            for (int d = 0; d < DIRECTIONS.size(); d++) {
                int newRow = row + DIRECTIONS[d][0];
                int newCol = col + DIRECTIONS[d][1];
                if (newRow >= 0 && newRow < N && newCol < N && newCol >= 0) {
                    int nextVal = graph[newRow][newCol];
                    int nextMin = min(now[2], nextVal);
                    int nextMax = max(now[3], nextVal);
                    // 사전에 허용 가능한 범위를 넘어서면 초과해야 함
                    if (nextMax - nextMin > answer) {
                        continue;
                    }

                    // 이전에 한번 간 적이 있는 범위라면 가지 말아야 함
                    if (visited[newRow][newCol][nextMax - nextMin]) {
                        continue;
                    }
                    // 그게 아니면 map에 집어넣고 queue에 넣음
                    visited[newRow][newCol][nextMax - nextMin] = true;
                    int* next = new int[4];
                    next[0] = newRow;
                    next[1] = newCol;
                    next[2] = nextMin;
                    next[3] = nextMax;
                    que.push(next);
                }
            }
        }

        bool find = false;
        for (int i = 0; i <= answer; i++) {
            if (visited[N - 1][N - 1][i]) {
                find = true;
                break;
            }
        }
        if (find) {
            answer -= diff;
        }         
    }

    cout << answer + 1 << "";

    auto end_time = high_resolution_clock::now(); // 종료 시간 측정
    auto duration = duration_cast<milliseconds>(end_time - start_time); // 실행 시간 계산

    //cout << "\nExecution Time: " << duration.count() << " ms\n"; // 실행 시간 출력

    return 0;
}

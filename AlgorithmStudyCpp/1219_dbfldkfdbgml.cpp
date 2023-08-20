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

/*
    플로이드 워셜 하되, 그 지점에서는 돈을 받으니까 cost를 빼면 된다.
*/

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, start, end, M;
    cin >> N >> start >> end >> M;

    vector<int*> edgeList;
    for (int i = 0; i < M; i++) {
        int* temp = new int[3];
        cin >> temp[0] >> temp[1] >> temp[2];
        edgeList.push_back(temp);
    }

    int* moneyList = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> moneyList[i];
    }

    for (int* edge : edgeList) {
        int to = edge[1];
        int money = moneyList[to];
        edge[2] -= money;
    }

    long long MAX = (long long)10000000000000000l;
    long long** graph = new long long* [N];
    for (int i = 0; i < N; i++) {
        graph[i] = new long long[N];
        for (int j = 0; j < N; j++) {
            graph[i][j] = MAX;
        }
    }
    bool** canGo = new bool* [N];
    for (int i = 0; i < N; i++) {
        canGo[i] = new bool[N];
        for (int j = 0; j < N; j++) {
            canGo[i][j] = false;
        }
    }

    for (int* edge : edgeList) {
        int from = edge[0];
        int to = edge[1];
        int cost = edge[2];
        canGo[from][to] = true;
        graph[from][to] = min(graph[from][to], (long long)cost);
    }

    // 플로이드
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (canGo[i][k] && canGo[k][j]) {
                    canGo[i][j] = true;
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    // 만약에 도착 도시에 도착하는 것이 불가능한 경우 gg 출력
    if (canGo[start][end] == false) {
        cout << "gg";
        return 0;
    }

    // 만약에 음수 사이클이 존재하는 경우 "Gee" 출력
    bool isCycle = false;
    for (int i = 0; i < N; i++) {
        if (canGo[start][i] && canGo[i][end] && canGo[i][i] && graph[i][i] < 0) {
            isCycle = true;
        }
    }

    if (isCycle || (start == end && canGo[start][end] && graph[start][end] < 0)) {
        cout << "Gee";
        return 0;
    }

    //// 만약에 시작 도시와 도착 도시가 같고, 도착 도시에 이미 도착했다면 금액만 갖고 끝
    if (start == end) {
        if (canGo[start][end] && graph[start][end] < 0) {
            cout << "Gee";
        } else {
            cout << moneyList[start];
        }
        return 0;
    }

    // 그게 아니면 비용에 시작한 곳에서의 금액 출력
    cout << graph[start][end] * -1 + moneyList[start];

    return 0;
}

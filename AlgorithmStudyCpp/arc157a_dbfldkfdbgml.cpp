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

using namespace std;

/*
    혹시 이거 DFS로 가지 잘 치면 될까?
*/
int N, A, B, C, D;

bool dfs(int cnt, int flag, int a, int b, int c, int d) {
    bool ret = false;
    if (cnt == N) {
        return A == a && B == b && C == c && D == d;
    }
    if (flag == 0) {
        // XX
        if (a + 1 <= A) {
            ret |= dfs(cnt + 1, 0, a + 1, b, c, d);
            if (ret) {
                return true;
            }
        }
        // XY
        if (b + 1 <= B) {
            ret |= dfs(cnt + 1, 1, a, b + 1, c, d);
            if (ret) {
                return true;
            }
        }
    }
    if (flag == 1) {
        // YX
        if (c + 1 <= C) {
            ret |= dfs(cnt + 1, 0, a, b, c + 1, d);
            if (ret) {
                return true;
            }
        }
        // YY
        if (d + 1 <= D) {
            ret |= dfs(cnt + 1, 1, a, b, c, d + 1);
            if (ret) {
                return true;
            }
        }
    }

    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> A >> B >> C >> D;

    // 두 번째 글자가 0일 때
    bool answer = false;
    if (1 <= A) {
        answer |= dfs(2, 0, 1, 0, 0, 0);
    }
    if (1 <= B) {
        answer |= dfs(2, 1, 0, 1, 0, 0);
    }
    if (1 <= C) {
        answer |= dfs(2, 0, 0, 0, 1, 0);
    }
    if (1 <= D) {
        answer |= dfs(2, 1, 0, 0, 0, 1);
    }
    if (N == 1 && A == 0 && B == 0 && C == 0 && D == 0) {
        answer = true;
    }
    
    if (answer) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
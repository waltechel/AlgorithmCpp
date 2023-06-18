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
    구현이 어려움
    기본적으로 YXXXY 스타일로 구성되어 있을 때 X를 모두 Y로 바꾸면 3개를 바꾸었는데 4개를 얻을 수 있음
    따라서 YXXX(...)XY 스타일로 구성되어 있는 연속된 X를 모두 Y로 바꾸는 것이 그리디하게 이득
    다만 다음 케이스들을 구체적으로 구현하는 것이 매우 어려움
    3 3
    XXX 정답 2
    3 2
    XXX 정답 1
    3 2
    XYX 정답 2
*/

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<int> yIndexList;

    int countOfX = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'Y') {
            yIndexList.push_back(i);
        } else {
            countOfX++;
        }
    }

    vector<int> diffList;
    for (int i = 1; i < yIndexList.size(); i++) {
        int from = yIndexList[i - 1];
        int to = yIndexList[i];
        int diff = to - from - 1;
        diffList.push_back(diff);
    }

    bool isThereIsNoMoreK = false;
    sort(diffList.begin(), diffList.end());
    int answer = 0;
    for (int i = 0; i < diffList.size(); i--) {
        int diff = diffList[i];
        if (K >= diff) {
            K -= diff;
            answer += diff + 1;
        } else {// K < diff 이제 더 이상 k가 남지 않았을 때
            isThereIsNoMoreK = true;
        }
    }

    if (isThereIsNoMoreK && K > 0) {
        answer += K;
    }
    
    cout << answer;

    return 0;
}
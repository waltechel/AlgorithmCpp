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

const string NO = "No\n", YES = "Yes\n";

/*
*/

bool isPalindrome(const string& line) {
    auto ret = line;
    reverse(ret.begin(), ret.end());
    return ret == line;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        long long N, K;
        string S;
        cin >> N >> K;
        cin >> S;
        K %= (N * 2);

        // 만약에 S` 문자열의 min(k, n)개의 왼쪽과, 
        // min(k, n)개의 오른쪽과 rev(S)가 같다면 정답은 Yes, 아니면 No
        // 이렇게 S`를 만들 수 있으면 된다.
        string X = S.substr(0, min(N, K));
        reverse(X.begin(), X.end());
        auto Y = X.substr(0, K - min(N, K));
        auto SS = Y + X;
        bool flag = false;
        if (isPalindrome(S + SS) && isPalindrome(SS + S)) {
            flag = true;
        } else {
            flag = false;
        }

        if (flag) {
            cout << YES;
        } else {
            cout << NO;
        }
    }

    return 0;
}
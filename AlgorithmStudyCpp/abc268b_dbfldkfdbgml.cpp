#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

// 문자열이 들어왔을 때 길이를 알 수 있는 방법은 무엇인가?

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string S, T;
	cin >> S >> T;

	if (S.size() > T.size()) {
		cout << "No";
	} else {
		bool find = true;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] != T[i]) {
				find = false;
			}
		}
		if (find) {
			cout << "Yes";
		} else {
			cout << "No";
		}
	}

	return 0;
}
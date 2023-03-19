#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

/*
	- 그래프 그리고 풀 거 같다.
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int N;
	cin >> N;

	vector<pair<string, string>> list;
	for (int i = 0; i < N; i++) {
		string S, T;
		cin >> S >> T;
		list.push_back({ S, T });
	}

	bool answer = true;
	for (int i = 0; i < N; i++) {
		string candi1 = list[i].first;
		bool flag1 = true;
		for (int j = 0; j < N; j++) {
			if (i == j) {
				continue;
			}
			string s1 = list[j].first;
			string s2 = list[j].second;
			if (candi1 == s1 || candi1 == s2) {
				flag1 = false;
				break;
			}
		}
		
		string candi2 = list[i].second;
		bool flag2 = true;
		for (int j = 0; j < N; j++) {
			if (i == j) {
				continue;
			}
			string s1 = list[j].first;
			string s2 = list[j].second;
			if (candi2 == s1 || candi2 == s2) {
				flag2 = false;
				break;
			}
		}
		
		if (flag1 == false && flag2 == false) {
			answer = false;
			break;
		}

	}

	if (answer) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}
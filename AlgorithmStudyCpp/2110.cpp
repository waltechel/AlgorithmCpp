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
#include<regex>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C;
	cin >> N >> C;
	
	vector<int> list;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		list.push_back(temp);
	}
	sort(list.begin(), list.end());

	int answer = 0;
	for (int i = (1 << 30); i >= 1; i /= 2) {
		answer += i;
		int cnt = 1;
		int place = list[0];
		for (int j = 1; j < list.size(); j++) {
			if (list[j] - place >= answer) {
				cnt++;
				place = list[j];
			}
		}

		if (cnt >= C) {

		} else {
			answer -= i;
		}
	}
	cout << answer;


	return 0;
}
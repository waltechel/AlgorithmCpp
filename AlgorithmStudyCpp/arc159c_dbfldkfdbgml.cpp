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

/*
	수열의 합이 N으로 나눠지지 않으면 무조건 No
	그 외 답 찾는 방법은 가장 작은 수에 가장 큰 수를 할당하는 식으로 그리디하게 접근하면 되는 문제
	(그리디하게 풀면 답이 나오지 않음)
*/

// 모든 값이 똑같으면 return true
bool isSafe(vector<int> list) {
	bool ret = true;
	for (int i = 0; i < list.size(); i++) {
		if (list[i] != list[0]) {
			return false;
		}
	}
	return true;
}

vector<int> add(vector<int> list) {
	vector<int> ret(list.size(), 0);
	vector<bool> checked(list.size(), false);
	for (int i = list.size(); i >= 1; i--) {
		int minIndex = -1;
		int minValue = 1000000000;
		for (int j = 0; j < list.size(); j++) {
			if (checked[j] == false && list[j] < minValue) {
				minValue = list[j];
				minIndex = j;
			}
		}
		ret[minIndex] = i;
		checked[minIndex] = true;
	}
	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
   
	int N;
	cin >> N;
	vector<int> list(N);
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += list[i];
	}

	if (sum % N != 0) {
		cout << "No";
		return 0;
	}
	
	int answer = 0;
	// 그게 아니면 그리디하게 풀면 되는 문제
	vector<vector<int>> answerList;
	while (!isSafe(list)) {
		answer++;
		vector<int> addList = add(list);
		for (int i = 0; i < N; i++) {
			list[i] += addList[i];
		}
		answerList.push_back(addList);
	}
	if (answer > 10000) {
		cout << "No\n";
		return 0;
	}

	cout << "Yes\n";
	cout << answer << "\n";
	for (vector<int> element : answerList) {
		for (int i = 0; i < element.size(); i++) {
			cout << element[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}
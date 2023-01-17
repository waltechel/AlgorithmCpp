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

// d 번은 다섯 번째라는 의도가 있을까요?
// 멀티셋이라는 놀라운 구조가 있네;;;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	/*
	for (int i = 0; i < 100; i += 3) {
		set.insert(i);
	}
	// lower_bound는 찾고자 하는 값 작지 않은(이상)이 처음으로 나타나는 위치
	cout << *(++set.lower_bound(96)) << "\n";

	// upper_bound는 찾고자 하는 값 보다 큰(초과)가 처음으로 나타나는 위치
	cout << *(++set.upper_bound(94)) << "\n";

	multiset<long long>::iterator iter_upper = set.upper_bound(101);
	multiset<long long>::iterator iter_lower = set.lower_bound(101);
	if (iter_lower != iter_upper) {
		// 있음
		cout << "있음";
	}
	*/

	multiset<long long, less<long long>> setAsc;
	multiset<long long, greater<long long>> setDesc;

	
	int Q;
	cin >> Q;
	multiset<long long>::iterator iter;
	multiset<long long>::iterator iter_upper;
	multiset<long long>::iterator iter_lower;
	bool find = false;
	for (int i = 0; i < Q; i++) {
		int command;
		cin >> command;
		long long x, k;
		int cnt = 0;
		switch (command) {
		case 1:
			cin >> x;
			setAsc.insert(x);
			setDesc.insert(x);
			break;
		case 2: // 작거나 같은, 그 중에서 k 번째 largest value
			cin >> x >> k;
			// upper_bound를 구해서 하거나, x+1을 lower_bound로 구해내는 방법이 있다
			iter_lower = setDesc.lower_bound(x);
			cnt = 1;
			find = false;
			for (iter = iter_lower; iter != setDesc.end(); iter++) {
				if (cnt == k) {
					cout << *iter << "\n";
					find = true;
					break;
				}
				cnt++;
			}
			if (find == false) {
				cout << "-1\n";
			}
			break;
		case 3: // 크거나 같은, 그 중에서 k 번째 smallest value
			cin >> x >> k;
			iter_lower = setAsc.lower_bound(x);
			cnt = 1;
			find = false;
			for (iter = iter_lower; iter != setAsc.end(); iter++) {
				if (cnt == k) {
					cout << *iter << "\n";
					find = true;
					break;
				}
				cnt++;
			}
			if (find == false) {
				cout << "-1\n";
			}
			break;
		default:
			break;
		}
	}

	return 0;
}
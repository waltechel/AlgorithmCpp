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

	multiset<long long> set;
	
	for (int i = 0; i < 100; i += 3) {
		set.insert(i);
	}
	// lower_bound는 찾고자 하는 값 작지 않은(이상)이 처음으로 나타나는 위치
	cout << *(++set.lower_bound(96)) << "\n";
	cout << set.end() - set.lower_bound(96) << "\n";

	// upper_bound는 찾고자 하는 값 보다 큰(초과)가 처음으로 나타나는 위치
	cout << *(++set.upper_bound(96)) << "\n";
	
	
	/*
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int command;
		cin >> command;
		int x, k;
		switch (command) {
		case 1:
			cin >> x;
			set.insert(x);
		case 2: // 작거나 같은, 그 중에서 k 번째 largest value
			cin >> x >> k;
		case 3: // 크거나 같은, 그 중에서 k 번째 smallest value
			cin >> x >> k;
			cout << set.lower_bound(x) - k << "\n";
		default:
			break;
		}
	}
	*/
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main() {

	vector<long long> list;
	int add = 1;
	list.push_back(1);
	for (long long i = 1; i < ((long long)1 << 32); ) {
		i += add;
		list.push_back(i);
		i += add;
		list.push_back(i);
		add += 1;
	}


	int N;
	cin >> N;
	for (int j = 0; j < N; j++) {
		int from, to;
		cin >> from >> to;
		int diff = to - from;
		cout << upper_bound(list.begin(), list.end(), diff) - list.begin() << "\n";
	}

	return 0;
}
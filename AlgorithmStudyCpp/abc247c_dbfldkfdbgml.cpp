#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	vector<string> list;
	list.push_back("0");
	list.push_back("1");

	for (int i = 2; i <= 16; i++) {
		string S = list[i - 1] + "," + to_string(i) + "," + list[i - 1];
		list.push_back(S);
	}

	int N;
	cin >> N;

	for (int i = 0; i < list[N].length(); i++) {
		if (list[N][i] == ',') {
			cout << " ";
		} else {
			cout << list[N][i];
		}
	}

	return 0;
}
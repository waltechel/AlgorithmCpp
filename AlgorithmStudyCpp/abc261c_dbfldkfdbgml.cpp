#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	map<long long, int> countMap;

	for (int i = 0; i < N; i++) {
		long long hashNum = 0;
		string line;
		cin >> line;

		// 1을 더해야 했다
		// 그런데 왜 insert는 안될까?
		for (int j = 0; j < line.length(); j++) {
			int a = (int)(line[j] - 'a') + 1;
			hashNum *= 26;
			hashNum += a;
		}
		int cnt = countMap[hashNum];
		countMap[hashNum]++;

		if (cnt == 0) {
			cout << line << "\n";
		} else {
			cout << line << "(" << cnt << ")" << "\n";
		}

	}

	return 0;
}


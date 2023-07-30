#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(0);

	vector<long long> list;
	long long input = 0;
	list.push_back(input);
	for (long long i = 26; input <= (long long) 1100000000000l; i += 26) {
		input += i;
		list.push_back(input);
	}

	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		long long N;
		cin >> N;

		for (int i = 0; i < list.size() - 1; i++) {
			if (list[i] <= N && N <= list[i + 1]) {
				long long diff = list[i + 1] - list[i];
				diff /= 26;
				N -= list[i];
				for (int j = 0; j < 26; j++) {
					if (N - diff <= 0) {
						cout << "Case #" << test << ": " << (char) ('A' + j) << "\n";
						break;
					}
					N -= diff;
				}
				break;
			}

		}
		// 총 27만 개 중에서 
	}
	
	return 0;
}
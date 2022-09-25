#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, Q;
	cin >> N >> K >> Q;

	vector<int> list;
	int num;
	for (int i = 0; i < K; i++) {
		cin >> num;
		list.push_back(num);
	}

	int index;
	for (int i = 0; i < Q; i++) {
		cin >> index;
		index--;
		// 마지막 순번일 때
		if (list[index] == N) {
			continue;
		} else {
		// 마지막 순번이 아닐 때
			if (index < K - 1 && list[index] + 1 == list[index + 1]) {
				continue;
			} else {
				list[index]++;
			}
		}
	}

	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}

	return 0;
}


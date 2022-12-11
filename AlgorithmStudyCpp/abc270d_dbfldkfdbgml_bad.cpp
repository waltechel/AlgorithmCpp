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

	int N, K;
	vector<int> list;

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		list.push_back(temp);
	}
	sort(list.begin(), list.end());

	int Takahashi = 0;
	int Aoki = 0;
	bool isTakahashi = true;
	while (N != 0) {
		if (isTakahashi) {
			for (int i = list.size() - 1; i >= 0; i--) {
				if (list[i] <= N) {
					N -= list[i];
					Takahashi += list[i];
					break;
				}
			}
			isTakahashi = false;
		} else {
			for (int i = list.size() - 1; i >= 0; i--) {
				if(list[i] <= N) {
					N -= list[i];
					Aoki += list[i];
					break;
				}
			}
			isTakahashi = true;
		}
	}

	cout << Takahashi;
		
	return 0;
}
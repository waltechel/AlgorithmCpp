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

	int N, Q;
	cin >> N >> Q;

	vector<int>* list = new vector<int>[N];
	for (int i = 0; i < N; i++) {
		int L;
		cin >> L;
		for (int j = 0; j < L; j++) {
			int temp;
			cin >> temp;
			list[i].push_back(temp);
		}
	}
	
	for (int i = 0; i < Q; i++) {
		int s, t;
		cin >> s >> t;
		cout << list[s - 1][t - 1] << "\n";
	}

	return 0;
}
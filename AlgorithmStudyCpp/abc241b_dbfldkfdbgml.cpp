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

	int N, M;
	cin >> N >> M;
	int* A = new int[N];
	int* B = new int[M];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	
	for (int i = 0; i < M; i++) {
		int b = B[i];
		bool find = false;
		for (int j = 0; j < N; j++) {
			if (A[j] == b) {
				A[j] = -1;
				find = true;
				break;
			}
		}
		if (find == false) {
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
	return 0;
}
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

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool* A = new bool[101];
	for (int i = 0; i <= 100; i++) {
		A[i] = false;
	}

	int* B = new int[5];
	cin >> B[0] >> B[1] >> B[2] >> B[3] >> B[4];
	
	for (int i = 0; i < 5; i++) {
		A[B[i]] = true;
	}

	int answer = 0;
	for (int i = 0; i <= 100; i++) {
		if (A[i] == true) {
			answer++;
		}
	}

	cout << answer << "";

	return 0;
}
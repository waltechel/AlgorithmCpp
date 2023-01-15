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

	int* A = new int[10];
	for (int i = 0; i < 10; i++) {
		cin >> A[i];
	}

	cout << A[A[A[0]]];
	
	return 0;
}
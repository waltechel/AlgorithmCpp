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

	int L, R;

	cin >> L >> R;

	string line = "atcoder";
	for (int i = L -1 ; i <= R -1 ; i++) {
		cout << line[i];
	}


	return 0;
}


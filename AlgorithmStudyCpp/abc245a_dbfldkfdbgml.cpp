#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

// 이렇게 하면 안될 거 같은데....

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int Takahashi = A * 60 + B;
	int Aoki = C * 60 + D + 1;

	if (Takahashi < Aoki) {
		cout << "Takahashi";
	} else {
		cout << "Aoki";
	}
	
	return 0;
}
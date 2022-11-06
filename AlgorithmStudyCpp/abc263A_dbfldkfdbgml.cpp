#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

int main() {

	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;
	int* CNT = new int[14];
	for (int i = 1; i <= 13; i++) {
		CNT[i] = 0;
	}
	CNT[A]++;
	CNT[B]++;
	CNT[C]++;
	CNT[D]++;
	CNT[E]++;

	bool hasThreeCount = false;
	bool hasTwoCount = false;
	for (int i = 1; i <= 13; i++) {
		if (CNT[i] == 3) {
			hasThreeCount = true;
		}
		if (CNT[i] == 2) {
			hasTwoCount = true;
		}
	}

	if (hasThreeCount && hasTwoCount) {
		cout << "Yes";
	} else {
		cout << "No";
	}


	return 0;
}


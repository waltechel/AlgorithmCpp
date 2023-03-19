#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int A, B, C, D, E, F, X;
	cin >> A >> B >> C >> D >> E >> F >> X;

	// 사이즈를 10000으로 잡으면 틀림 ㅠㅠ 넉넉하게 그냥 할걸
	vector<int> Takahashi(100000, 0);
	vector<int> Aoki(100000, 0);
	for (int i = 0; i < 100; i++) {
		for (int j = 1; j <= A; j++) {
			Takahashi[j + (A + C) * i] = B;
		}
		for (int j = A + 1; j <= A + C; j++) {
			Takahashi[j + (A + C) * i] = 0;
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 1; j <= D; j++) {
			Aoki[j + (D + F) * i] = E;
		}
		for (int j = D + 1; j <= D + F; j++) {
			Aoki[j + (D + F) * i] = 0;
		}
	}

	for (int i = 1; i <= X; i++) {
		Takahashi[i] += Takahashi[i - 1];
		Aoki[i] += Aoki[i - 1];
	}

	//cout << Takahashi[X] << " " << Aoki[X] << "\n";

	if (Takahashi[X] > Aoki[X]) {
		cout << "Takahashi";
	} else if (Takahashi[X] < Aoki[X]) {
		cout << "Aoki";
	} else {
		cout << "Draw";
	}

	return 0;
}
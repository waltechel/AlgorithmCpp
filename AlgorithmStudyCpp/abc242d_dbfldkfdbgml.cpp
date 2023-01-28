#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

char change(long long n, char c) {
	if (c == 'A' && n % 2 == 1) {
		return 'C';
	} else if (c == 'A' && n % 2 == 0) {
		return 'B';
	} else if (c == 'B' && n % 2 == 1) {
		return 'A';
	} else if (c == 'B' && n % 2 == 0) {
		return 'C';
	} else if (c == 'C' && n % 2 == 1) {
		return 'B';
	} else {
		return 'A';
	}
}

/*
	줄일 수 있는 최대한 줄여 내고 0번째에서는 글자가 도니까 거기서만 골라내면 된다.
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	string S;
	cin >> S;

	int Q;
	cin >> Q;

	for (int query = 0; query < Q; query++) {
		char answer = 'A';
		long long t_back, k_back;
		cin >> t_back >> k_back;
		// 어차피 수가 A, B, C 세 개 밖에 없으므로 
		// A라고 가정해서 돌려보고
		// B라고 가정해서 돌려보고
		// C라고 가정해서 돌려본다.
		long long t, k;
		t = t_back;
		k = k_back;
		char candi = 'A';
		while (k != 1 && t >= 1) {
			candi = change(k, candi);
			++k /= 2;
			t--;
		}
		if (t == 0) {
			char origin = S[k - 1];
			if (origin == candi) {
				answer = 'A';
			}
		} else { // k가 1이고 t가 남는 경우
			t %= 3; // 점프를 한다.
			while (t >= 1) {
				candi = change(k, candi);
				t--;
			}
			char origin = S[k - 1];
			if (origin == candi) {
				answer = 'A';
			}
		}

		t = t_back;
		k = k_back;
		candi = 'B';
		while (k != 1 && t >= 1) {
			candi = change(k, candi);
			++k /= 2;
			t--;
		}
		if (t == 0) {
			char origin = S[k - 1];
			if (origin == candi) {
				answer = 'B';
			}
		} else { // k가 1이고 t가 남는 경우
			t %= 3; // 점프를 한다.
			while (t >= 1) {
				candi = change(k, candi);
				t--;
			}
			char origin = S[k - 1];
			if (origin == candi) {
				answer = 'B';
			}
		}

		t = t_back;
		k = k_back;
		candi = 'C';
		while (k != 1 && t >= 1) {
			candi = change(k, candi);
			++k /= 2;
			t--;
		}
		if (t == 0) {
			char origin = S[k - 1];
			if (origin == candi) {
				answer = 'C';
			}
		} else { // k가 1이고 t가 남는 경우
			t %= 3; // 점프를 한다.
			while (t >= 1) {
				candi = change(k, candi);
				t--;
			}
			char origin = S[k - 1];
			if (origin == candi) {
				answer = 'C';
			}
		}


		cout << answer << "\n";
	}

	return 0;
}
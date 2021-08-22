#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {

	string S1, S2;
	cin >> S1 >> S2;

	string P = S1 + S2;
	int* f = new int[P.length()];

	for (int i = 0; i < P.length(); i++) {
		f[i] = 0;
	}

	for (int i = 1, j = 0; i < P.length(); ) {
		while (i < P.length() && j < P.length() && P[i] == P[j]) {
			f[i++] = ++j;
		}
		if (j == 0) {
			i++;
		} else {
			j = f[j - 1];
		}
	}

	/*
		P의 길이 k인 접두사와 접미사는 일단 무조건 같다.
		따라서 길이가 k 이하인 S의 접미사는 S[...k - 1]의 접미사이기도 하다.
		따라서 k 다음으로 긴 접미사를 찾으려면 f[k - 1]을 확인한다.
	*/
	vector<int> ret;
	int k = P.length();
	while (k > 0) {
		ret.push_back(k);
		k = f[k - 1];
	}

	for (int i = ret.size() - 1; i >= 0; i--) {
		cout << ret[i] << " ";
	}

	return 0;
}
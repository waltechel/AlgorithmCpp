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
		P�� ���� k�� ���λ�� ���̻�� �ϴ� ������ ����.
		���� ���̰� k ������ S�� ���̻�� S[...k - 1]�� ���̻��̱⵵ �ϴ�.
		���� k �������� �� ���̻縦 ã������ f[k - 1]�� Ȯ���Ѵ�.
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
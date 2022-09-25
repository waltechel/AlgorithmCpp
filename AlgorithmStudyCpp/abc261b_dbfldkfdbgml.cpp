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

	int N;
	cin >> N;
	string* map = new string[N];
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				if (map[i][j] != '-') {
					flag = false;
				}
			} else {
				if (map[i][j] == 'D' && map[j][i] != 'D') {
					flag = false;
				}
				if (map[i][j] == 'W' && map[j][i] != 'L') {
					flag = false;
				}
				if (map[i][j] == 'L' && map[j][i] != 'W') {
					flag = false;
				}
			}

		}
	}

	if (flag) {
		cout << "correct";
	} else {
		cout << "incorrect";
	}

	return 0;
}


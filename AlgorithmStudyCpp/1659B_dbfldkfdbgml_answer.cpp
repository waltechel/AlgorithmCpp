#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

/*
	브루트포스로 풀어본다.
*/

struct Answer {
	string line;
	int times[5];
};

bool compare(const Answer& a1, const Answer& a2) {
	if (a1.line.compare(a2.line) != 0) {
		return a1.line < a2.line;
	} else {
		for (int i = 0; i < 5; i++) {
			if (a1.times[i] != a2.times[i]) {
				return a1.times[i] < a2.times[i];
			}
		}
		return 0;
	}
}

int times[5];
vector<Answer> list;
string line;
int n, k;

void dfs(int index, int cnt);
void check(int i);

int main() {

	int TEST;
	cin >> TEST;
	for (int test = 0; test < TEST; test++) {
		cin >> n >> k;
		cin >> line;
		
		for (int i = 0; i < 5; i++) {
			times[i] = 0;
		}

		for (int i = 0; i < (int) line.length(); i++) {
			if (1 <= k) {
				dfs(i, 1);
				check(i);
				times[i]--;
			}
		}

		if (list.empty() == false) {
			sort(list.begin(), list.end(), compare);
			cout << list[list.size() - 1].line << "\n";
			for (int i = 0; i < 5; i++) {
				cout << list[list.size() - 1].times[i] << " ";
			}
			cout << "\n";
			list.clear();
		} else {
			cout << line << "\n";
		}

	}
	return 0;
}

void check(int index) {
	for (int i = 0; i < line.length(); i++) {
		if (index == i) {
			continue;
		} else {
			if (line[i] == '0') {
				line[i] = '1';
			} else {
				line[i] = '0';
			}
		}
	}
}

void dfs(int index, int cnt) {

	times[index]++;
	check(index);

	if (cnt == k) {
		Answer candi;
		candi.line = line;
		for (int i = 0; i < 5; i++) {
			candi.times[i] = times[i];
		}
		list.push_back(candi);
		return;
	}

	for (int i = 0; i < line.length(); i++) {
		dfs(i, cnt + 1);
		check(i);
		times[i]--;
	}
}
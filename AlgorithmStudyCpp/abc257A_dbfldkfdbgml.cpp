#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, X;
	cin >> N >> X;

	string line = "";
	for (char i = 'a'; i <= 'z'; i++) {
		for (int j = 0; j < N; j++) {
			line += i;
		}
	}
	cout << line[X - 1] << " ";

	return 0;
}


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<unordered_set>
#include<regex>

using namespace std;

const string NO = "No\n", YES = "Yes\n";

/*
*   답이 충분히 짧은 시간 안에 나오게 되어 있음
*/

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> list;
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			for (int c = 0; c <= 9; c++) {
				for (int d = 0; d <= 9; d++) {
					for (int e = 0; e <= 9; e++) {
						for (int f = 0; f <= 9; f++) {
							int i = 0;
							i += (a * 100000000 + a * 10000000);
							i += (b * 1000000);
							i += (c * 100000);
							i += (d * 10000 + d * 1000);
							i += (e * 100 + e);
							i += (f * 10);
							list.push_back(i);
						}
					}
				}
			}
		}
	}

	int index;
	cin >> index;

	cout << list[index - 1];

	return 0;
}
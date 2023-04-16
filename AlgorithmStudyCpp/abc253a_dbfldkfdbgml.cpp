#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(0);

	int a, b, c;
	cin >> a >> b >> c;
	if ((a <= b && b <= c) || (c <= b && b <= a)) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	
	return 0;
}
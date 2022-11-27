#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string line;
	cin >> line;

	cout << line[line.length() / 2];

	return 0;
}
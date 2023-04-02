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
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(0);

	string S;
	cin >> S;

	S += S;
	S += S;
	S += S;
	S += S;
	S += S;
	S += S;

	for (int i = 0; i < 6; i++) {
		cout << S[i] << "";
	}

	
    return 0;
}
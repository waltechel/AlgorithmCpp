#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<cmath>
using ll = long long;
using namespace std;
const int MAX_N = 1001, INF = 1e9, SWITCH=10;
int pos[MAX_N];
int divi(char* b, int p, bool _print) {
	int& ret = pos[p];
	if (ret == -1) {
		if (b[p] != 'x')
			ret = p;
		else
			ret = divi(b, divi(b, divi(b, divi(b, p + 1, false) + 1, false) + 1, false) + 1, false);
	}

	if (_print) {
		printf("%c", b[p]);
		if (b[p] == 'x') {
			int p1 = divi(b, p + 1, false);
			int p2 = divi(b, p1 + 1, false);
			int p3 = divi(b, p2 + 1, true);
			divi(b, p3 + 1, true);

			divi(b, p + 1, true);
			divi(b, p1 + 1, true);
		}
	}

	return ret;
}
int main() {
	double ans;
	char b[MAX_N];
	int T;
	scanf("%d\n", &T);
	while (T--) {
		scanf("%s", b);
		memset(pos, -1, sizeof pos);

		divi(b, 0, 1);
		puts("");
	}
	return 0;
}
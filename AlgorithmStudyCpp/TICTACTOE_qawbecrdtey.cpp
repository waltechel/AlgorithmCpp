#include <iostream>
using namespace std;
inline bool fff(int B, int x) { return (B & x) == x; }
inline bool won(int B) {
	return fff(B, 7) || fff(B, 73) || fff(B, 273)
	|| fff(B, 146) || fff(B, 84) || fff(B, 292)
	|| fff(B, 56) || fff(B, 448);
}
inline bool turn(int O, int X) {
	int o = 0, x = 0;
	for(int i = 0; i < 9; i++) {
		o += (O >> i) & 1;
		x += (X >> i) & 1;
	}
	return x - o;
}
inline int left(int O, int X) { return 511 ^ (O | X); }
int f(int dp[512][512], int O, int X) {
	if(dp[O][X] != -2) return dp[O][X];
	if(won(X)) return dp[O][X] = 1;
	if(won(O)) return dp[O][X] = -1;
	int l = left(O, X);
	if(!l) return dp[O][X] = 0;
	int tie = 1;
	if(!turn(O, X)) { // X turn
		for(int i = 0; i < 9; i++) {
			if(l & (1 << i)) {
				if(f(dp, O, X | (1 << i)) == 1) return dp[O][X] = 1;
				if(!dp[O][X | (1 << i)]) tie = 0;
			}
		}
		return dp[O][X] = -tie;
	}
	else { // O turn
		for(int i = 0; i < 9; i++) {
			if(l & (1 << i)) {
				if(f(dp, O | (1 << i), X) == -1) return dp[O][X] = -1;
				if(!dp[O | (1 << i)][X]) tie = 0;
			}
		}
		return dp[O][X] = tie;
	}
}
inline char const *ff(int x) {
	switch(x) {
		case -1: return "o";
		case 0: return "TIE";
		case 1: return "x";
		default: __builtin_unreachable();
	}
}
template<typename ...Args>
void p(Args ...args);
template<>
void p() {}
template<typename ...Args>
void p(int x, Args&& ...args) {
	cout << x << '\n';
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout << (((x >> (i * 3 + j)) & 1) ? 'x' : '.') << ' ';
		} cout << '\n';
	} cout << '\n';
	p(std::forward<Args>(args)...);
}
int main() {
	// p(7, 73, 273, 146, 84, 292, 56, 448);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int dp[512][512];
	for(auto &i : dp) for(int &j : i) j = -2;
	int t; cin >> t; while(t--) {
		char c[3][4];
		int O = 0, X = 0;
		for(int i = 0; i < 3; i++) {
			cin >> c[i];
			for(int j = 0; j < 3; j++) {
				O |= ((c[i][j] == 'o') << (i * 3 + j));
				X |= ((c[i][j] == 'x') << (i * 3 + j));
			}
		}
		cout << ff(f(dp, O, X)) << '\n';
	}
}
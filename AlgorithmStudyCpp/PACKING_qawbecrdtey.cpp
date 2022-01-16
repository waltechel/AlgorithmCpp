#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Data {
	vector<string> list;
	int urgency;
	Data() : list(), urgency() {}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n, w;
		cin >> n >> w;
		auto a = new Data*[n + 1];
		a[0] = new Data[w + 1];
		for(int i = 1; i <= n; i++) {
			a[i] = new Data[w + 1];
			string name; int volume, urgency;
			cin >> name >> volume >> urgency;
			a[i][0].list = a[i - 1][0].list;
			a[i][0].urgency = a[i - 1][0].urgency;
			for(int j = 1; j <= w; j++) {
				int x = a[i - 1][j].urgency;
				int y = a[i - 1][j - volume].urgency + urgency;
				if(j >= volume && y > x) {
					a[i][j].list = a[i - 1][j - volume].list;
					a[i][j].list.push_back(name);
					a[i][j].urgency = y;
				}
				else {
					a[i][j].list = a[i - 1][j].list;
					a[i][j].urgency = x;
				}
			}
		}
		cout << a[n][w].urgency << ' ' << a[n][w].list.size() << '\n';
		for(auto const &now : a[n][w].list) {
			cout << now << '\n';
		}
		for(int i = 0; i <= n; i++) delete[] a[i];
		delete[] a;
	}
}
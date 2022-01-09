#include <iostream>
#include <vector>
using namespace std;
struct Data { vector<int> list; };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;
	auto a = new int[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	auto b = new int[m + 1];
	for(int i = 1; i <= m; i++) cin >> b[i];
	auto arr = new Data*[n + 1];
	arr[0] = new Data[m + 1];
	for(int i = 1; i <= n; i++) {
		arr[i] = new Data[m + 1];
		Data &d = arr[i][0];
		for(int j = 1; j <= m; j++) {
			arr[i][j].list = arr[i - 1][j].list;
			if(a[i] > b[j] && arr[i][j].list.size() > d.list.size()) d = arr[i][j];
			if(a[i] == b[j]) {
				arr[i][j].list = d.list;
				arr[i][j].list.push_back(a[i]);
			}
		}
	}
	Data &d = arr[n][0];
	for(int i = 1; i <= m; i++) {
		if(arr[n][i].list.size() > d.list.size()) d = arr[n][i];
	}
	cout << d.list.size() << '\n';
	for(auto now : d.list) {
		cout << now << ' ';
	}
}
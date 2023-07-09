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
#include <bitset>

using namespace std;

/*
*   정확히 중간을 선택하는 게 안될 확률이 가장 높다
*	-> 아니다, 3, 6 (2, 2, 2)의 경우 중간을 선택하면 되는데, 이렇게 하면 문제가 풀리지 않는다.
*	-> 하나를 남기고 앉히는 것이 안될 확률이 가장 높다(최대한 많은 1개 좌석을 만들어야 한다)
* 
*/

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L;
	cin >> N >> L;

	priority_queue<int> pq;
	pq.push(L);

	bool flag = true;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		int maxLineChair = pq.top();
		pq.pop();
		maxLineChair -= temp;
		if (maxLineChair > 0) {
			int a = 1; // 그냥 무조건 한자리를 비운다.
			int b = maxLineChair - a;
			if (a > 0 && b >= 0) {
				pq.push(a);
			}
			if (b > 0) {
				pq.push(b);
			}
		}
		if (maxLineChair < 0) {
			flag = false;
		}
	}

	if (flag) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	
	return 0;
}
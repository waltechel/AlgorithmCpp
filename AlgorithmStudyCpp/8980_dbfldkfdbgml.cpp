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
#include<bitset>

using namespace std;

/*
	시작점 기준으로는 두 번째 예제가 되지 않음
	도착점이나 거리 기준으로 해야 하는 거 같음
	도착점까지는 했는데 구현을 어떻게 해야하는지는 모르겠어서 다음 출처에서 가져옴
	https://lu-coding.tistory.com/42
*/

bool comp(int* a, int* b) {
	if (a[1] != b[1]) {
		return a[1] < b[1];
	} else if (a[0] != b[0]) {
		return a[0] < b[0];
	}
	return a[2] < b[2];
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C;
	cin >> N >> C;
	int M;
	cin >> M;
	vector<int*> list;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		int* temp = new int[3];
		temp[0] = from;
		temp[1] = to;
		temp[2] = cost;
		list.push_back(temp);
	}
   
	// from, to, cost 순으로 정렬
	sort(list.begin(), list.end(), comp);
	
	int truck[2001] = {0};
	long long answer = 0;
	for (int* car : list) {
		int from = car[0];
		int to = car[1];
		int cost = car[2];
		int max_truck = 0; //현재 택배가 지나가야 할 truck배열값 중 가장큰거
		for (int j = from; j < to; j++) {
			max_truck = max(truck[j], max_truck);
		}
		int capacity = min(cost, C - max_truck);//가져갈 수 있는 택배 수 구하기위한 변수 (원래 택배수,가능한공간)
		for (int j = from; j < to; j++) { //출발부터 도착전까지 가능한 택배수 할당
			truck[j] += capacity;
		}
		answer += capacity; //트럭에 성공적으로 싣은 택배
	}

	cout << answer;

    return 0;

}
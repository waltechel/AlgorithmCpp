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
#include<regex>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int*> stack;

	int answer = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (stack.size() >= 1) {
			int* top = stack.top();
			if (top[0] != temp) {
				int* element = new int[2];
				element[0] = temp;
				element[1] = 1;
				stack.push(element);
				answer++;
			} else {
				top[1]++;
				answer++;
				if (top[0] == top[1]) {
					stack.pop();
					answer -= top[1];
				} 
			}
		} else {
			int* element = new int[2];
			element[0] = temp;
			element[1] = 1;
			stack.push(element);
			answer++;
		}
		cout << answer << "\n";
	}
	
	return 0;
}
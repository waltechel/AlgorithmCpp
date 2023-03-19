#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

/*
	답보고 함
    그냥 정렬하지 말고 카운트를 세서 개수 간에 서로 곱해버리면 된다;;
    그리고 M을 p로 나누는 모든 경우의 수를 더한 게 결국 OMlogM이 되므로 이렇게 해도 된다...
*/
using namespace std;

const int MAX = 200000;

int main() {
  
    int n;
    cin >> n;
    
    vector<int> c(MAX + 1);
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x] += 1;
    }

    long long ans = 0;
    for (int q = 1; q <= MAX; ++q) {
        for (int r = 1; q * r <= MAX; ++r) {
            ans += (long long)c[q] * c[r] * c[q * r];
        }
    }
    cout << ans << '\n';
    return 0;
}
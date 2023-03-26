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

vector<int> getPrimeList(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    isPrime[0] = false; 
    isPrime[1] = false;
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    vector<int> primes = getPrimeList(1000000);

    long long answer = 0;
    long long N;
    cin >> N;
    for (int prime : primes) {
        long long q = (long long)prime * prime * prime;
        int pMax = min(N / q, (long long) prime -1);

        // upper_bound를 사용하여 primes에서 max보다 작거나 같은 수들의 개수를 구함
        int count = upper_bound(primes.begin(), primes.end(), pMax) - primes.begin();

        answer += count;
    }

    cout << answer;

	return 0;
}
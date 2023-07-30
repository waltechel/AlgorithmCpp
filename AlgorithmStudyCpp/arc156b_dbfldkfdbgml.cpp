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

using namespace std;
const long long MOD = 998244353;
const string NO = "No\n", YES = "Yes\n";

vector<long long> fac{ 1, 1 };  // 팩토리얼
vector<long long> inv{ 1, 1 };  // 역원
vector<long long> finv{ 1, 1 }; // 역수

int binom(int n, int r) {
    // cout << "fac[n] : " << fac[n] << ", finv[n - r] % MOD : " << finv[n - r] % MOD << ", finv[r] % MOD : " << finv[r] % MOD << "\n";
    return 1LL * fac[n] * finv[n - r] % MOD * finv[r] % MOD;
}

/*
    Let us write an integer between 0 and x exactly K−M. 
    How many multisets can be obtained in this way?
    - 조합을 계산해야 하는데 미리 계산해놓기가 어려우므로 factorial을 계산해두어야 한다.
*/
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    for (int i = 2; i < 500000; ++i) {
        fac.push_back(1ll * fac.back() * i % MOD);
        inv.push_back((MOD - 1ll * (MOD / i) * inv[MOD % i] % MOD) % MOD);
        finv.push_back(1ll * finv.back() * inv.back() % MOD);
    }

    vector<int> exist(500001, 0);
    for (int v : A) {
        exist[v] = 1;
    }

    long long need = 1;
    long long res = 0;
    for (int i = 0; i < N + K; i++) {
        if (need > K) {
            break;
        }
        int rest = K - need;
        long long plus = binom(rest + i, i);
        res += plus;
        res %= MOD;
        if (!exist[i]) {
            need++;
        }
    }

    cout << res << "\n";
    
    return 0;
}
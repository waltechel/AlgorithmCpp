#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll MAX = 1000000000 + 100;
vector<vector<ll>> comb;
vector<char> ans;

ll cal_comb(ll n, ll m) // n C m
{
    if (m == 0 || n == m)
        return 1;

    ll& ret = comb[n][m];
    if (ret != -1)
        return ret;

    return ret = min(MAX, cal_comb(n - 1, m) + cal_comb(n - 1, m - 1));
}

void rec(ll n, ll m, ll k)
{
    // cout << n << " " << m << " " << k << "\n";
    if (n == 0)
    {
        for (ll i = 0; i < m; i++)
            ans.push_back('o');

        return;
    }
    if (m == 0)
    {
        for (ll i = 0; i < n; i++)
            ans.push_back('-');

        return;
    }

    ll half = cal_comb(n + m - 1, n - 1);

    if (half < k)
    {
        ans.push_back('o');
        rec(n, m - 1, k - half);
    }
    else
    {
        ans.push_back('-');
        rec(n - 1, m, k);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll testCase;
    cin >> testCase;

    comb = vector<vector<ll>>(202, vector<ll>(102, -1));
    while (testCase--)
    {
        ll n, m, k;
        cin >> n >> m >> k;

        ans = vector<char>();
        rec(n, m, k);

        for (ll i = 0; i < ans.size(); i++)
            cout << ans[i];
        cout << "\n";
    }
}
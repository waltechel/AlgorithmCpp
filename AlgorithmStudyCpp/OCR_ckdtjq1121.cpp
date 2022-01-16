#include <bits/stdc++.h>

using namespace std;

vector<string> words;
map<string, int> dict;
vector<double> firstP;
vector<vector<double>> nextP;
vector<vector<double>> errorP;
vector<vector<double>> dp;
vector<vector<pair<int, int>>> parent;

int m, q, n;
vector<string> s;
// si번째 순서에 words[wi]가 있을 확률
double rec(int si, int wi)
{
    int di = dict[s[si]]; // si번째 순서로 인식된 단어의 idx
    if (si == 0)
        return firstP[wi] * errorP[wi][di];

    double& ret = dp[si][wi];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 1; i <= m; i++)
    {
        double tmp = rec(si - 1, i) * nextP[i][wi] * errorP[wi][di]; // wi 다음에 i단어가 온 상황
        if (ret < tmp)
        {
            ret = tmp;
            parent[si][wi] = { si - 1, i };
        }
    }

    return ret;
}
pair<int, int> backTracking()
{
    double ret = 0;
    pair<int, int> root;
    for (int i = 1; i <= m; i++)
    {
        double tmp = rec(n - 1, i);
        if (ret < tmp)
        {
            ret = tmp;
            root = { n - 1, i };
        }
    }

    return root;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> q;

    words = vector<string>(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> words[i];
        dict[words[i]] = i;
    }

    firstP = vector<double>(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> firstP[i];

    nextP = vector<vector<double>>(m + 1, vector<double>(m + 1)); // i번째 단어 이후 j번째 단어일 확률
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            cin >> nextP[i][j];

    errorP = vector<vector<double>>(m + 1, vector<double>(m + 1)); // i번째 단어를 j번째 단어로 분류할 확률
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            cin >> errorP[i][j];

    string line;
    for (int i = 0; i < q; i++)
    {
        cin >> n;

        dp = vector<vector<double>>(n, vector<double>(m + 1, -1));
        // s의 i번째 단어가 j단어일 확률 = s의 i-1번째 단어 다음 i번째 단어로 j단어가 나올 확률 * j단어가 인식된 문장의 i번째 단어로 인식될 확률
        // dp[i][j] = dp[i-1][k] * nextP[i-1][j] * errorP[j][i]

        s = vector<string>();
        getline(cin, line);
        stringstream ss(line);
        string token;
        while (getline(ss, token, ' '))
            if (token != "")
                s.push_back(token);

        parent = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m + 1));
        pair<int, int> root;
        root = backTracking();

        vector<string> ans(n);
        for (int i = 0; i < n; i++)
        {
            int idx = root.first, word = root.second;
            ans[idx] = words[word];

            root = parent[idx][word];
        }

        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
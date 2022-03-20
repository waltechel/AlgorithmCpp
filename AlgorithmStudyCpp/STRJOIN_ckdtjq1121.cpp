#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n;
        cin >> n;

        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            pq.push(tmp);
        }

        int ans = 0;
        while (!pq.empty())
        {
            int first = pq.top();
            pq.pop();

            if (pq.empty()) // 모든 문자열을 합쳐서 1개만 남았을때 종료
                break;

            int second = pq.top();
            pq.pop();

            int newOne = first + second;
            ans += newOne;
            pq.push(newOne);
        }

        cout << ans << "\n";
    }
}
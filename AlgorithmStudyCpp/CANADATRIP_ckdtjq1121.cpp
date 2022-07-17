#include <bits/stdc++.h>

using namespace std;
struct input
{
    int L, M, G;
};
int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n, k;
        cin >> n >> k;

        // k번째 표지판의 위치
        // L M G : L - 도시의 위치, M = M미터 전부터 표지판, G = G미터 마다 표지판
        // [L-M, L]
        vector<input> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].L >> a[i].M >> a[i].G;

        int left = 0, right = 8030000 * 2 + 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            int tmp = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i].L <= mid) // 모든 표지판 cnt
                    tmp += a[i].M / a[i].G + 1;
                else // [start, mid] 표지판 cnt
                {
                    int start = a[i].L - a[i].M;
                    if (start <= mid)
                        tmp += (mid - start) / a[i].G + 1;
                }
            }

            if (k > tmp)
                left = mid + 1;
            else
                right = mid - 1;
        }

        cout << left << "\n";
    }
}
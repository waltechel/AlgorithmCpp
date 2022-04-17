#include <bits/stdc++.h>

using namespace std;

vector<int> divideNum;

const int HIGH = 10000000;
int main()
{
    divideNum = vector<int>(HIGH + 1, 1);
    for (int i = 2; i <= HIGH; i++)
    {
        for (int j = 1; i * j <= HIGH; j++)
            divideNum[i * j]++;
    }

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n, lo, hi;
        cin >> n >> lo >> hi;

        int cnt = 0;
        for (int i = lo; i <= hi; i++)
            if(divideNum[i] == n)
                cnt++;

        cout << cnt << "\n";
    }
}
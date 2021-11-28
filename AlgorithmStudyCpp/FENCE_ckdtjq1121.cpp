#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int maxArea(int start, int end)
{
    if (start == end)
        return arr[start];

    int mid = (start + end) / 2;

    int lS = maxArea(start, mid);
    int rS = maxArea(mid + 1, end);

    int ret = max(lS, rS);

    // mid�� mid+1�� ��ġ�鼭 ���� �� �ִ� �ִ� ���� ã��
    int lo = mid, hi = mid + 1;
    int height = min(arr[lo], arr[hi]);

    ret = max(ret, height * 2);

    while (start < lo || hi < end)
    {
        // ���̰� ���������� ���� ���� ���� ���̷� ����� �ִ� �� ū �簢���� ã�� �� �ִ�.
        if (hi < end && (lo == start || arr[lo - 1] < arr[hi + 1]))
        {
            hi++;
            height = min(height, arr[hi]);
        }
        else
        {
            lo--;
            height = min(height, arr[lo]);
        }

        ret = max(ret, height * (hi - lo + 1));
    }

    return ret;
}

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

        arr = vector<int>(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int ans = maxArea(0, n - 1);

        cout << ans << "\n";
    }
}
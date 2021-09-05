// reverse insert sorting
#include<bits/stdc++.h>

using namespace std;
const int MAX = 50000;
int arr[MAX];
int sorted[MAX];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < n; i++)
		{
			sorted[i] = i + 1;
		}

		int tmp;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i - arr[i]; j < i; j++)
			{
				tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}

		}

		for (int i = 0; i < n; i++)
		{
			cout << sorted[i] << " ";
		}
		cout << endl;
	}
}

// insert sorting  : i - 1 까지 정렬되있을 대 i번째 원소를 i - 1까지 중 원소 사이에 삽입을 하며 정렬을함
// reverse  -> 정렬된 i번째 원소를 i의 원래 위치로 되돌려냄
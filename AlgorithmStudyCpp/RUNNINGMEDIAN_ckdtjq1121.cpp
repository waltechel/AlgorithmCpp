#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int  MAX = 200001;
const int INF = 987654321;
int A[MAX];

vector<int> minheap; // bigger than median
vector<int> maxheap; // smaller than median


// if 정렬  되어 있는 A에 삽입이 log n -> n log n
// 삽입이 log n에 이루어져야 함
int minheapPush(int elem)
{
	minheap.push_back(elem);

	int j = minheap.size() - 1;
	int tmp;
	while (j > 0 && minheap[j] < minheap[(j - 1) / 2])// 부모 보다 자식이 작으면 swap
	{
		tmp = minheap[j];
		minheap[j] = minheap[(j - 1) / 2];
		minheap[(j - 1) / 2] = tmp;

		j = (j - 1) / 2;
	}

	return 0;
}
int minheapPop()
{
	int ret = minheap[0];
	int n = minheap.size();	// 0 ~ n -1

	minheap[0] = minheap[n - 1]; // n - 1 자리 제거, 0 자리 값 반환
	minheap.pop_back();
	int j = 0;
	int tmp;
	while (j * 2 + 1 < n - 1)
	{
		if (j * 2 + 1 == n - 2)	// 왼쪽 자식 밖에 없는 경우
		{
			if (minheap[j] > minheap[j * 2 + 1])	// 부모가 크다
			{
				tmp = minheap[j];
				minheap[j] = minheap[j * 2 + 1];
				minheap[j * 2 + 1] = tmp;
			}
			break;
		}

		if (minheap[j * 2 + 1] < minheap[j * 2 + 2])	// 왼쪽 자식이 더 작은 경우
		{
			if (minheap[j] > minheap[j * 2 + 1])	// 부모가 더 크다
			{

				tmp = minheap[j];
				minheap[j] = minheap[j * 2 + 1];
				minheap[j * 2 + 1] = tmp;

				j = j * 2 + 1;
			}
			else
				break;
		}
		else									// 오른쪽 자식이 더 작은 경우
		{
			if (minheap[j] > minheap[j * 2 + 2])		// 부모가 더 크다
			{
				tmp = minheap[j];
				minheap[j] = minheap[j * 2 + 2];
				minheap[j * 2 + 2] = tmp;

				j = j * 2 + 2;
			}
			else
				break;
		}
	}

	return ret;
}

int maxheapPush(int elem)
{
	maxheap.push_back(elem);

	int j = maxheap.size() - 1;
	int tmp;
	while (j > 0 && maxheap[j] > maxheap[(j - 1) / 2]) // 부모 보다 자식이 크면 swap
	{
		tmp = maxheap[j];
		maxheap[j] = maxheap[(j - 1) / 2];
		maxheap[(j - 1) / 2] = tmp;

		j = (j - 1) / 2;
	}

	return 0;
}
int maxheapPop()
{
	int n = maxheap.size();	// 0 ~ n -1

	int ret = maxheap[0];
	maxheap[0] = maxheap[n - 1]; // n - 1 자리 제거, 0 자리 값 반환
	maxheap.pop_back();
	int j = 0;
	int tmp;
	while (j * 2 + 1 < n - 1)
	{
		if (j * 2 + 1 == n - 2)	// 왼쪽 자식 밖에 없는 경우
		{
			if (maxheap[j] < maxheap[j * 2 + 1])	// 부모가 더 작으면
			{
				tmp = maxheap[j];
				maxheap[j] = maxheap[j * 2 + 1];
				maxheap[j * 2 + 1] = tmp;
			}
			break;
		}

		if (maxheap[j * 2 + 1] > maxheap[j * 2 + 2]) // 왼쪽 자식이 더 큰 경우
		{
			if (maxheap[j] < maxheap[j * 2 + 1])	// 부모가 더 작으면
			{
				tmp = maxheap[j];
				maxheap[j] = maxheap[j * 2 + 1];
				maxheap[j * 2 + 1] = tmp;

				j = j * 2 + 1;
			}
			else
				break;
		}
		else								// 오른쪽 자식이 더 큰 경우
		{
			if (maxheap[j] < maxheap[j * 2 + 2])	// 부모가 더 작으면
			{
				tmp = maxheap[j];
				maxheap[j] = maxheap[j * 2 + 2];
				maxheap[j * 2 + 2] = tmp;

				j = j * 2 + 2;
			}
			else
				break;
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;
	for (; testCase > 0; testCase--)
	{
		int n, a, b;
		cin >> n >> a >> b;

		ll prev = 1983; // A[i]
		ll next = (prev * a + b) % 20090711; // A[i + 1]

		// i = 1
		int median = prev;
		maxheap.push_back(prev);

		prev = next;
		next = (prev * a + b) % 20090711;

		int tmp;
		int ans = median;
		// i = 2 ~ n
		for (int i = 2; i <= n; i++)
		{
			if (median < prev)
			{
				minheapPush(prev);	// 중간 값보다 큰 값이면 minheap에 추가

				if (minheap.size() > maxheap.size()) // min3 max2 => min2 max3 
				{
					tmp = minheapPop();
					maxheapPush(tmp);
				}
			}
			else
			{
				maxheapPush(prev);	// 중간 값보다 작은 값이면 maxheap에 추가

				if (maxheap.size() - 1 > minheap.size())	// min2 max4 => min3 max3
				{
					tmp = maxheapPop();
					minheapPush(tmp);
				}
			}
			//		debuging
			//cout << maxheap.size() << " " << minheap.size() << endl;
			//for (int j = 0; j < minheap.size(); j++)
			//{
			//	cout << minheap[j] << " ";
			//}
			//cout << " min" << endl;
			//for (int j = 0; j < maxheap.size(); j++)
			//{
			//	cout << maxheap[j] << " ";
			//}
			//cout << " max" << endl;
			//cout << median << " median" << endl;

			median = maxheap[0];	// always max of maxheap become median
			ans = (ans + median) % 20090711;

			prev = next;
			next = (prev * a + b) % 20090711;
		}

		maxheap.clear();
		minheap.clear();
		cout << ans << endl;
	}
	return 0;
}

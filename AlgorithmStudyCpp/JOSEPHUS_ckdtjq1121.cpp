#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int n, k;
		cin >> n >> k;

		vector<bool> alive(n, true);
		int seqCnt;
		int timingDie = 0;
		alive[0] = false;
		for (int j = 1; j < n - 2; j++)
		{
			seqCnt = 0;

			for (int a = timingDie + 1; a <= 1000001; a++)
			{
				if (alive[a % n])
					seqCnt++;

				if (seqCnt == k)
				{
					timingDie = a % n;
					alive[timingDie] = false;

					break;
				}
			}
		}

		for (int j = 0; j < n; j++)
		{
			if (alive[j])
				cout << j + 1 << " ";
		}
		cout << "\n";
	}
}
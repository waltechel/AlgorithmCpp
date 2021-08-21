#include <iostream>
#include<vector>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int num;
		cin >> num;
		vector<int> fence;
		int tmp;
		for (int j = 0; j < num; j++)
		{
			cin >> tmp;
			fence.push_back(tmp);
		}

		int ret = 0;
		int area;
		for (int j = 0; j < num; j++)
		{
			area = fence[j];
			for (int k = j + 1; k < num; k++)
			{
				if (fence[j] <= fence[k])
				{
					area += fence[j];
				}
				else
					break;
			}
			for (int k = j - 1; k >= 0; k--)
			{
				if (fence[j] <= fence[k])
				{
					area += fence[j];
				}
				else
					break;
			}

			ret = max(ret, area);
		}

		cout << ret << "\n";
	}
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> getPartialMatch(const string& N)
{
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;

	while (begin + matched < m)
	{

		if (N[begin + matched] == N[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}

	return pi;
}

vector<int> StartIndexsOfBString(const string& a, const string& b)
{
	int n = a.size();
	int m = b.size();

	vector<int> pi = getPartialMatch(b);

	vector<int> ret;
	int begin = 0, matched = 0;
	while (begin + matched < n)
	{
		if (matched < m && a[begin + matched] == b[matched])
		{
			matched++;
		}
		else
		{
			if (matched == m)
				ret.push_back(begin);

			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}

	if (matched == m)
		ret.push_back(begin);

	return ret;
}
int main()
{
	int testCase;
	cin >> testCase;


	for (int i = 0; i < testCase; i++)
	{
		int n;
		cin >> n;

		vector<string> picture;
		for (int j = 0; j < n + 1; j++)
		{
			string tmp;
			cin >> tmp;

			picture.push_back(tmp);
		}

		int size = picture[1].size();


		// kmp fuction
		int currentIndex = size;

		int ret = 0;
		vector<int> tickList;
		for (int j = 1; j < n + 1; j++)
		{
			picture[j - 1] += picture[j - 1] + picture[j - 1];
			tickList = StartIndexsOfBString(picture[j - 1], picture[j]);
			int mintick = 987654321;
			for (int k = 0; k < tickList.size(); k++)
			{
				if (j % 2 == 1)
				{
					if (currentIndex - tickList[k] > 0 && mintick > currentIndex - tickList[k])
					{
						mintick = currentIndex - tickList[k];
					}
				}
				else
				{
					if (tickList[k] - currentIndex > 0 && mintick > tickList[k] - currentIndex)
					{
						mintick = tickList[k] - currentIndex;
					}
				}
			}
			ret += mintick;
		}

		cout << ret << "\n";
	}
}
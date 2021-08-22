#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getParticialMatch(const string& str)
{
	int size = str.size();

	vector<int> pi(size, 0);
	int begin = 1, matched = 0;
	while (begin + matched < size)
	{
		if (str[begin + matched] == str[matched])
		{
			pi[begin + matched] = ++matched; //  길이를 저장해야하기 때문에 +1을 한다
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

int maxOverlap(const string& a, const string& b)
{
	// make pi of revStr O(N)
	vector<int> pi = getParticialMatch(b);

	int n = a.size(), m = b.size();
	int begin = 0, matched = 0;
	while (begin < n)
	{
		if (matched < m && a[begin + matched] == b[matched])
		{
			++matched;

			if (begin + matched == n)
			{
				return matched;
			}
		}
		else
		{
			if (matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}

	return 0;
}
int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		string str;
		cin >> str;

		int size = str.size();

		// make revStr  O(N)
		string revStr;
		for (int i = 0; i < size; i++)
		{
			revStr += str[size - 1 - i];
		}

		// In str, find longest part of revStr to Use KMP O(N)
		cout << 2 * size - maxOverlap(str, revStr) << endl;
	}
	return 0;

}
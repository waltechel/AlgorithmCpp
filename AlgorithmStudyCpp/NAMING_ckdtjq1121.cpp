#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	string father, mother;
	cin >> father >> mother;

	string name = father;
	name += mother;

	vector<int> pi(name.size(), 0);
	stack<int> ret;


	// pre-processing of kmp algorithm 
	int j = 0;
	for (int i = 1; i < name.size(); i++)
	{
		while (j > 0 && name[i] != name[j])
		{
			j = pi[j - 1];
		}

		if (name[i] == name[j])
			pi[i] = ++j;
	}

	//ret
	int length = name.size();
	while (length)
	{
		if (length != 0)
			ret.push(length);

		length = pi[length - 1];
	}


	// output
	while (!ret.empty())
	{
		cout << ret.top();
		ret.pop();

		if (!ret.empty())
			cout << " ";
	}
}
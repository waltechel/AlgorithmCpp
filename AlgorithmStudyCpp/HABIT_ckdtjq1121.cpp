// ���ڿ����� k�� �̻� �����ϴ� ���� �� �κ� ���ڿ��� ã���� �Ѵ�.


// 1. �κ� ���ڿ��� �� k�� �̻� ��Ÿ�� �͵��� ã�´�.
// 2. ���� �ִ� ���̸� ã�´�.
// 
// ���̻� �迭�� ���λ� = �κ� ���ڿ�
//
// ���̻� �迭 ��ü�� ������ �Ǿ� �ִ�
// => ���̻� �迭�� ���λ� �� ������ �Ǿ� �ִ�
// => �Ȱ��� �κ� ���ڿ��� �ٷ� ���� ���̻翡�� ã�� �� �ִ�.
// 
// => i ���̻�� i + k - 1 ���̻翡�� ����Ǵ� ���λ�� k�� �̻� �����ϴ� �κ��� ���̻��� ���λ�( �κ� ���ڿ�)�̴�
// 
// 1. ���ڿ��� ���̻� �迭�� �����.
// 2. ���̻� �迭�� A[i] ~ A[i + k - 1]���� ����Ǵ� ���λ縦 ã�´�.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct Comparator {
	vector<int>& group;
	int t;

	Comparator(vector<int>& _group, int _t) : group(_group), t(_t)
	{
		group = _group;
		t = _t;
	}

	bool operator () (int a, int b)
	{
		if (group[a] != group[b])
			return group[a] < group[b];

		return group[a + t] < group[b + t];
	}
};

// ���̻� �迭 �����
vector<int> getsuffixArray(const string& S)
{

	int n = S.size();
	int t = 1;
	vector<int> group(n + 1);	// t ���ڸ� �� ���� �� ���� �� ���� �׷� �����ֱ� �������� ���缭
	for (int i = 0; i < n; i++)
	{
		group[i] = S[i];
	}

	group[n] = -1;

	vector<int> perm(n);	// ���ĵ� ���̻��� ���� �ε���
	for (int i = 0; i < n; i++)
	{
		perm[i] = i;
	}

	while (t < n)
	{
	
		// t���� ����
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T); 

		// 2t���� ������ �غ�
		t *= 2;
		if (t >= n) break;

		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for (int i = 1; i < n; i++)
		{
			if (compareUsing2T(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		}

		group = newGroup;
	}

	return perm;
}

// i ���̻�� i + k - 1 ���̻��� �ִ���� ���λ��� ����
int commonPrefix(const string& S, int i, int j)
{
	int k = 0; // ����Ǵ� �κ�
	while (i + k < S.size() && j + k < S.size() && S[i + k] == S[j + k])
		k++;

	return k;
}

// S���� k�� �̻� �����ϴ� �κ� ���ڿ��� �ִ� ����
int maxcommonPrefix(const string& S, int k)
{
	int n = S.size();
	vector<int> suffixArray = getsuffixArray(S);


	int ret = 0;
	for (int i = 0; i + k - 1 < n; i++)
	{
		// i ���̻�� i + k - 1 ���̻��� �ִ���� ���λ��� ����
		ret = max(ret, commonPrefix(S, suffixArray[i], suffixArray[i + k - 1]));
	}

	return ret;
}

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int k;
		cin >> k;

		string S;
		cin >> S;

		// S���� k�� �̻� �����ϴ� �κ� ���ڿ��� �ִ� ����
		cout << maxcommonPrefix(S, k) << "\n";
	}
}
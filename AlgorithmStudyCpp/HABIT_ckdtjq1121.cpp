// 문자열에서 k번 이상 등장하는 가장 긴 부분 문자열을 찾으려 한다.


// 1. 부분 문자열들 중 k번 이상 나타는 것들을 찾는다.
// 2. 그중 최대 길이를 찾는다.
// 
// 접미사 배열의 접두사 = 부분 문자열
//
// 접미사 배열 자체는 정렬이 되어 있다
// => 접미사 배열의 접두사 도 정렬이 되어 있다
// => 똑같은 부분 문자열을 바로 다음 접미사에서 찾을 수 있다.
// 
// => i 접미사와 i + k - 1 접미사에서 공통되는 접두사는 k번 이상 등장하는 부분은 접미사의 접두사( 부분 문자열)이다
// 
// 1. 문자열의 접미사 배열을 만든다.
// 2. 접미사 배열중 A[i] ~ A[i + k - 1]에서 공통되는 접두사를 찾는다.

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

// 접미사 배열 만들기
vector<int> getsuffixArray(const string& S)
{

	int n = S.size();
	int t = 1;
	vector<int> group(n + 1);	// t 글자를 비교 했을 때 같은 것 끼리 그룹 지어주기 사전순에 맞춰서
	for (int i = 0; i < n; i++)
	{
		group[i] = S[i];
	}

	group[n] = -1;

	vector<int> perm(n);	// 정렬된 접미사의 시작 인덱스
	for (int i = 0; i < n; i++)
	{
		perm[i] = i;
	}

	while (t < n)
	{
	
		// t개로 정렬
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T); 

		// 2t개로 정렬할 준비
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

// i 접미사와 i + k - 1 접미사의 최대공통 접두사의 길이
int commonPrefix(const string& S, int i, int j)
{
	int k = 0; // 공통되는 부분
	while (i + k < S.size() && j + k < S.size() && S[i + k] == S[j + k])
		k++;

	return k;
}

// S에서 k번 이상 등장하는 부분 문자열의 최대 길이
int maxcommonPrefix(const string& S, int k)
{
	int n = S.size();
	vector<int> suffixArray = getsuffixArray(S);


	int ret = 0;
	for (int i = 0; i + k - 1 < n; i++)
	{
		// i 접미사와 i + k - 1 접미사의 최대공통 접두사의 길이
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

		// S에서 k번 이상 등장하는 부분 문자열의 최대 길이
		cout << maxcommonPrefix(S, k) << "\n";
	}
}
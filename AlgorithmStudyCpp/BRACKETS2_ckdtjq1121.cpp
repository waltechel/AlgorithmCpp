#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	string bracheks;

	for (int i = 0; i < testCase; i++)
	{
		cin >> bracheks;
		//getline(cin, bracheks);  // 사용방법을 모르겟다
		stack<char> checkBracheks;
		for (int j = 0; j < bracheks.size(); j++)
		{
			if (bracheks.at(j) == '(')
			{
				checkBracheks.push('(');
			}
			else if (bracheks.at(j) == '{')
			{
				checkBracheks.push('{');
			}
			else if (bracheks.at(j) == '[')
			{
				checkBracheks.push('[');
			}
			else
			{

				if (!checkBracheks.empty())	//스택이 empty 일때 top에 접근시 RTE가 난다 아마도 top의 인덱스가 -1이기 때문
				{
					if (bracheks.at(j) == ')')
					{
						if (checkBracheks.top() == '(')
							checkBracheks.pop();
						else
							break;
					}
					else if (bracheks.at(j) == '}')
					{
						if (checkBracheks.top() == '{')
							checkBracheks.pop();
						else
							break;
					}
					else if (bracheks.at(j) == ']')
					{
						if (checkBracheks.top() == '[')
							checkBracheks.pop();
						else
							break;
					}
				}
				else
				{
					checkBracheks.push('0');
				}
			}

		}


		if (checkBracheks.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
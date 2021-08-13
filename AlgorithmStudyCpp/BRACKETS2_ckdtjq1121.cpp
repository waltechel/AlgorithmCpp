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
		//getline(cin, bracheks);  // ������� �𸣰ٴ�
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

				if (!checkBracheks.empty())	//������ empty �϶� top�� ���ٽ� RTE�� ���� �Ƹ��� top�� �ε����� -1�̱� ����
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
#include <iostream>

using namespace std;

const int INF = 987654321;

// ������ �� �ִ� ����ġ��
int switchs[10][5] = {
	{0, 1, 2, -1, -1},
	{3, 7, 9, 11, -1},
	{4, 10, 14, 15, -1},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15, -1},
	{3, 14, 15, -1, -1},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};
// �ð��� �ð���
int clocks[16];
// ��� 12������ Ȯ���ϴ� �Լ�
bool checkAns()
{
	for (int i = 0; i < 16; i++)
	{
		if (clocks[i] != 12)
			return 0;
	}
	return 1;
}
int minSwitching(int nSwitch)
{
	if (nSwitch == 10 )
	{
		if (checkAns()) 
			return 0;
		else
			return INF; 
	}

	int clock;
	int ret = INF;
	for (int i = 0; i < 4; i++) // brute-force�� ��� ����ġ ���� ����� �õ� (4*10) ^ 10
	{
		ret = min(ret, minSwitching(nSwitch + 1) + i);

		for (int j = 0; j < 5; j++)
		{
			clock = switchs[nSwitch][j];
			if (clock == -1)
				break; 

            // 3 ~ 12 �ð��� ����
			clocks[clock] %= 12;
			clocks[clock] += 3;
		}
	}
	return ret;
}
int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cin >> clocks[j];
		}
		int ans = minSwitching(0);

		if (ans == INF)		// ���� ���� ��� -1 ���
			cout << -1 << "\n";
		else
		cout << minSwitching(0) << "\n"; 
	}
}
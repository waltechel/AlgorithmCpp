#include <iostream>

using namespace std;

int main()
{
	int c;	// case
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		int resultCount = 0;
		int n, k, m, l;
		cin >> n >> k >> m >> l;

		int endSubjectBit = 0;
		//bool* endSubject = (bool*)malloc(n * sizeof(bool)); // �̼��� ���� ���� üũ ǥ
		//for (int j = 0; j < n; j++)			// false �̼����� �������� �ʱ�ȭ
		//{
		//	endSubject[j] = false;
		//}
		int* preSubjectBit = (int*)malloc(n * sizeof(int));
		//bool** preSubject = (bool**)malloc(n * sizeof(bool*)); // �������� üũ ǥ
		for (int j = 0; j < n; j++)			//  false ���������� �ƴ����� �ʱ�ȭ
		{
			preSubjectBit[j] = 0;
			/*for (int a = 0; a < n; a++)
			{
				preSubject[j][a] = false;
			}*/

		}

		int nCount;
		int temp;
		for (int j = 0; j < n; j++)		// �������� ���� �Է�
		{
			cin >> nCount;
			for (int a = 0; a < nCount; a++)
			{
				cin >> temp;

				preSubjectBit[j] |= (1 << temp);
				/*preSubject[j][temp] = true;*/

			}

		}

		int* semesterBit = (int*)malloc(m * sizeof(int));
		//bool** semester = (bool**)malloc(m * sizeof(bool*));
		for (int j = 0; j < m; j++)			//  false �б⿡ �ִ� ������ �ƴ����� �ʱ�ȭ
		{
			semesterBit[j] = 0;
			/*semester[j] = (bool*)malloc(n * sizeof(bool));
			for (int a = 0; a < n; a++)
			{
				semester[j][a] = false;
			}*/
		}

		int mCount;

		for (int j = 0; j < m; j++)		// �б� ���� �Է�
		{
			cin >> mCount;
			for (int a = 0; a < mCount; a++)
			{
				cin >> temp;

				semesterBit[j] |= (1 << temp);
				//semester[j][temp] = true;	

			}

		}

		int tempEndSubjectBit = 0;
		//bool* tempEndSubject = (bool*)malloc(n * sizeof(bool)); // �ӽ� �̼� �Ϸ� ǥ
		//for (int j = 0; j < n; j++)		// false �̼����� �������� �ʱ�ȭ
		//{
		//	tempEndSubject[j] = false;
		//}

		// �б� ����
		int result = 0;
		bool failFlag;
		for (int j = 0; j < m; j++)	// �б�
		{
			for (int a = 0; a < n; a++)		//�б��� ����
			{
				//if (!semester[j][a]) // [j]�б⿡ [a] ������ ���� ��� �н�
				if ((semesterBit[j] & (1 << a)) == 0)
				{

					continue;
				}

				//if (endSubject[a]) // endSubject[a]�� �̹� ���� �Ͽ��� ��� �н�
				if (endSubjectBit & (1 << a))
				{
					continue;
				}

				failFlag = false;
				for (int b = 0; b < n; b++)
				{
					//if (preSubject[a][b] && !endSubject[b]) // a�� ���� �������� b�� �ְ� b�� ���� ���� �� ���� ��	a�� �������� ����
					if ((preSubjectBit[a] & (1 << b)))
					{
						if ((endSubjectBit & (1 << b)) == 0)
						{
							failFlag = true;
							break;
						}
					}
				}

				if (!failFlag)	// �������� �ʾҴٸ� -> ���� ������� �����Ϸ� ���� ��� ������ �� ����
				{
					//tempEndSubject[a] = true; // ���� �Ϸ�
					tempEndSubjectBit |= (1 << a);
				}
			}


			// �� �б� ��

			//for (int a = 0; a < n; a++)	// �� �б�� �ٸ� ���� �ִ���?
			//{
				//if (endSubject[a] != tempEndSubject[a])	
			// 
			if (endSubjectBit != tempEndSubjectBit)
			{
				result++;
				//for (int a = 0; a < n; a++)	// �̹� �б⿡�� ���� �Ϸ��� ����  ���� �Ϸ� ǥ�� �߰�
				//{
				//	if (endSubject[a] != tempEndSubject[a])
				//	{
				//		endSubject[a] = endSubject[a] || tempEndSubject[a];
				//	}
				//}				
				endSubjectBit |= tempEndSubjectBit;
			}
			// �����Ϸ� ���� ���� ī��Ʈ
			resultCount = 0;
			for (int a = 0; a < n; a++)
			{
				//if (endSubject[a])
				if (endSubjectBit & (1 << a))
				{
					resultCount++;
				}
			}
			// ��ǥ ���� �� �̻�  ���� �Ϸ� ->
			if (resultCount >= k)
				break;
		}

		// ��� ���
		if (resultCount < k)
			cout << "IMPOSSIBLE" << "\n";
		else
			cout << result << "\n";
	}
	// ���� ������ �� �ִ� ������ ������ ���� �� �б⿡�� ������ ������ �Ѵ�. => �ּ� �б⸦ �������� ����
	// �б� ���� ���� �߿� �ּ� �бⰡ ���� ��  => recursive + dp
	// �� �б⿡ ���� �� �ִ� ���� �� l(L)�� ��������
}



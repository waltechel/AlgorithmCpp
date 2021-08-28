// ���� ��ȸ + ���� ��ȸ => ���� ��ȸ �����
#include <iostream>
#include <vector>
using namespace std;

int rootIndex = 0;

void makePostorder(vector<int> preorder, vector<int> inorder, int leftBound, int rightBound)
{
	// ��� ��� ��ȸ ��
	if (rootIndex == preorder.size())
		return;

	int midBound = -1; // ���� ���� root�� ���� ���

	// ���� �� root ã��
	for (int i = 0; i < inorder.size(); i++)
	{
		if (inorder[i] == preorder[rootIndex])
		{
			midBound = i;
			break;
		}
	}


	// ���� ��ȸ : �� -> �� -> ��Ʈ ���� ��ȸ
	rootIndex++;	// ���� index ã��
	// ���� ��尡 �ִ� ���		���� ��� ��ȸ
	if (leftBound != midBound)
		makePostorder(preorder, inorder, leftBound, midBound - 1);

	// ������ ��尡 �ִ� ���		������ ��� ��ȸ
	if (midBound != rightBound)
		makePostorder(preorder, inorder, midBound + 1, rightBound); // ������ Ʈ�� ��ȸ

	// ���� ���� ��Ʈ�� �־��� ���		��Ʈ �� ���
	if (midBound != -1)
		cout << inorder[midBound] << " ";	// ���� ��ȸ

	return;
}

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		// init
		rootIndex = 0;

		// input
		int numOfNode;
		cin >> numOfNode;

		vector<int> preorder(numOfNode, 0);
		for (int i = 0; i < numOfNode; i++)
		{
			cin >> preorder[i];
		}

		vector<int> inorder(numOfNode, 0);
		for (int i = 0; i < numOfNode; i++)
		{
			cin >> inorder[i];
		}

		// output
		makePostorder(preorder, inorder, 0, numOfNode - 1);
		cout << "\n";
	}
}


// ���� + ���� ��ȸ ==> ���� ��ȸ�� ���� �� �ִ�.
// 
//  ex)
//  Ʈ��
//          27
//     16        54
//   9        36    72
//     12
//���� ��ȸ ���� �����ڽ� ������ �ڽ� ( ���� ��ȸ���� �� �� �ִ� �� ��Ʈ ���)
// ==> 27 16 9 12 54 36 72
// 
//���� ��ȸ �����ڽ� ���� ������ �ڽ� ( ���� ��ȸ���� �� �� �ִ� ���� ���� ���)
// ==> 9 12 16 27 36 54 72
// 
//���� ��ȸ ���� �ڽ� ������ �ڽ� ���� 
// ==> 12 9 16 36 72 54 27
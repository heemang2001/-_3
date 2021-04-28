#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M; // ���� ���� , ��û�� ���� ����
vector<int> Height_DDuck; // ���� ���� ����

int nResult;

int binary_Search(vector<int>& arr, int target, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int mid = (start + end) / 2;
	long long total = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > mid)
		{
			total += ( arr[i] - mid ); // �߶����� ���� �� ���
		}
	}

	if (total == M)
	{
		return mid;
	}

	// ���� ���� ������ ��� �� ���� �ڸ��� ( ���� �κ� Ž�� )
	else if (total < M)
	{
		return binary_Search(Height_DDuck, M, start, mid - 1);
	}

	// ���� ���� ����� ��� �� �ڸ��� ( ������ �κ� Ž�� )
	else
	{
		return binary_Search(Height_DDuck, M, mid + 1, end);
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int nTemp = 0;

		cin >> nTemp;

		Height_DDuck.push_back(nTemp);
	}

	// �̺� Ž��
	nResult = binary_Search(Height_DDuck, M, 0, *max_element(Height_DDuck.begin(), Height_DDuck.end()));

	if (nResult == -1)
	{
		cout << "�ش� ���̰� ������ �ʽ��ϴ�" << '\n';
	}

	else
	{
		cout << nResult << '\n';
	}

	return 0;
}
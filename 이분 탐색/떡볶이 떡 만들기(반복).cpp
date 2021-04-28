// 4 6
// 19 15 10 17
// ��� : 15

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Height_DDuck;

int nResult;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int nTemp = 0;

		cin >> nTemp;

		Height_DDuck.push_back(nTemp);
	}

	int nStart = 0;
	int nEnd = *max_element(Height_DDuck.begin(), Height_DDuck.end());		

	while (nStart <= nEnd)
	{
		long long ltotal = 0;
		int nMid = (nStart + nEnd) / 2;

		for (int i = 0; i < N; i++)
		{
			if (Height_DDuck[i] > nMid)
			{
				ltotal += Height_DDuck[i] - nMid;
			}
		}

		// ã���� ����
		if (ltotal == M) 
		{
			nResult = nMid;
			break;
		}

		// �ڸ� ���� ���� ������ ==> �������̵�
		else if (ltotal > M)
		{
			nResult = nMid;
			nStart = nMid + 1;
		}

		// �ڸ� ���� ���� ���� ==> �����̵�
		else
		{
			nEnd = nMid - 1;
		}
	}

	cout << nResult << '\n';

	return 0;
}
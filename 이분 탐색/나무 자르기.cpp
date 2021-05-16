#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vecTree;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int answer = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int nTemp = 0;
		cin >> nTemp;
		vecTree.push_back(nTemp);
	}

	int start = 0;
	int end = *max_element(vecTree.begin(), vecTree.end());

	while (start <= end)
	{
		int mid = (start + end) / 2;
		long long lRemain = 0;

		for (int i = 0; i < N; i++)
		{
			if (vecTree[i] > mid)
			{
				lRemain += vecTree[i] - (long long)mid;
			}			
		}

		if (lRemain == M)
		{
			answer = mid;
			break;
		}
		
		else if(lRemain < M)
		{
			end = mid - 1;
		}

		else if (lRemain > M)
		{
			start = mid + 1;
			answer = mid;
		}
	}

	cout << answer << '\n';

	return 0;
}

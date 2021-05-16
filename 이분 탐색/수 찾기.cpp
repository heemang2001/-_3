#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int N, M;
vector<int> A;

int main()
{
	ios_base::sync_with_stdio(0);

	cin.tie(0); //cin 속도 향상 위해
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp = 0;

		cin >> nTemp;

		A.push_back(nTemp);
	}

	sort(A.begin(), A.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int nTemp = 0;

		cin >> nTemp;

		int start = 0;
		int end = N - 1;
		int answer = 0;

		while (start <= end)
		{
			if (nTemp > A[N - 1])
			{
				break;
			}

			int mid = (start + end) / 2;

			if (nTemp == A[mid])
			{
				answer = 1;				
				break;
			}

			else if(nTemp < A[mid])
			{
				end = mid - 1;
			}

			else if (nTemp > A[mid])
			{
				start = mid + 1;
			}
		}

		cout << answer << '\n';
	}
}

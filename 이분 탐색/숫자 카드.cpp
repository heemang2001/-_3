#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> vecNumberCard;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecNumberCard.push_back(nTemp);
	}

	sort(vecNumberCard.begin(), vecNumberCard.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		long long start = 0;
		long long end = N - 1;	
		int answer = 0;

		int nTemp;
		cin >> nTemp;

		while (start <= end)
		{
			long long mid = (start + end) / 2;	

			if (nTemp == vecNumberCard[mid])
			{
				answer = 1;				
				break;
			}

			else if (nTemp < vecNumberCard[mid])
			{
				end = mid - 1;				
			}

			else if (nTemp > vecNumberCard[mid])
			{
				start = mid + 1;				
			}			
		}

		cout << answer << " ";
	}

	return	0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
long long answer;
vector<long long> vecRanRope;

bool IsPossible(long long lenth)
{
	long long nTemp = 0;

	for (int i = 0; i < K; i++)
	{
		nTemp += vecRanRope[i] / lenth;
	}

	if (nTemp >= N)
	{
		return true;
	}

	else
	{
		return false;
	}
}

int main()
{
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		long long nTemp;
		cin >> nTemp;
		vecRanRope.push_back(nTemp);
	}

	sort(vecRanRope.begin(), vecRanRope.end());

	long long start = 1;
	long long end = vecRanRope.back();

	while (start <= end)
	{
		long long mid = (start + end) / 2;

		if (IsPossible(mid))
		{
			answer = max(answer, mid);
			start = mid + 1;
		}

		else
		{
			end = mid - 1;
		}
	}

	cout << answer << '\n';

	return 0;
}
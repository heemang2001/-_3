#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C;
int answer;
vector<int> vecMap;

bool IsPossible(int distance)
{
	int cnt = 1;
	int front = vecMap.front();

	for (int i = 1; i < N; i++)
	{
		if (vecMap[i] - front >= distance)
		{
			cnt++;
			front = vecMap[i];
		}
	}

	//
	if (cnt >= C)
	{
		return true;
	}

	return false;
}

int main()
{
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecMap.push_back(nTemp);
	}

	sort(vecMap.begin(), vecMap.end());
	
	int start = 1;								// 최소 거리
	int end = vecMap.back() - vecMap.front();	// 최대 거리

	while (start <= end)
	{
		int mid = (start + end) / 2;

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
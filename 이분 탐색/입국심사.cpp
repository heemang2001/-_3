#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// n = 기다리는 사람 수
// times = 심사하는데 걸리는 시간
// times.size() = 심사관수
long long solution(int n, vector<int> times)
{
	long long answer = 0;

	sort(times.begin(), times.end());

	long long start = 1;
	long long end = times[times.size()-1] * (long long)n;
	long long mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		long long count = 0;

		for (int i = 0; i < times.size(); i++)
		{
			count += mid / times[i];
		}

		if (count < n)
		{
			start = mid + 1;
		}

		else
		{
			answer = mid;
			end = mid - 1;
		}
	}

	return answer;
}

int main()
{
	cout << solution(6, { 7,10 }) << '\n';	// 28
	cout << solution(1, { 2,2 }) << '\n';	// 2
	cout << solution(1, { 1 }) << '\n';		// 1

	return 0;
}
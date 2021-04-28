#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M; // 떡의 개수 , 요청한 떡의 길이
vector<int> Height_DDuck; // 떡의 개별 높이

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
			total += ( arr[i] - mid ); // 잘랐을때 떡의 양 계산
		}
	}

	if (total == M)
	{
		return mid;
	}

	// 떡의 양이 부족한 경우 더 많이 자르기 ( 왼쪽 부분 탐색 )
	else if (total < M)
	{
		return binary_Search(Height_DDuck, M, start, mid - 1);
	}

	// 떡의 양이 충분한 경우 덜 자르기 ( 오른쪽 부분 탐색 )
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

	// 이분 탐색
	nResult = binary_Search(Height_DDuck, M, 0, *max_element(Height_DDuck.begin(), Height_DDuck.end()));

	if (nResult == -1)
	{
		cout << "해당 길이가 나오지 않습니다" << '\n';
	}

	else
	{
		cout << nResult << '\n';
	}

	return 0;
}
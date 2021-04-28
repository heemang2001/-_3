#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 값이 [left_value, right_value] 인 데이터의 개수를 반환하는 함수
int countByRange(vector<int>& v, int leftValue, int rightValue)
{
	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
	vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	return rightIndex - leftIndex;
}

int Find_x_Amount(vector<int>& arr, int x)
{
	int low = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	int upper = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

	int Value = upper - low;

	if (Value > 0)
	{
		return Value;
	}

	else
	{
		return -1;
	}	
}

int main()
{
	int N, x; // N개의 수열중 x인 원소의 개수가 몇개인가? 하나도없으면 -1출력
	vector<int> arr;

	cin >> N >> x;

	for (int i = 0; i < N; i++)
	{
		int nTemp = 0;

		cin >> nTemp;

		arr.push_back(nTemp);
	}

	sort(arr.begin(), arr.end());

	cout << Find_x_Amount(arr, x) << '\n';

	return 0;
}
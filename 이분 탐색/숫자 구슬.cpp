#include <iostream>
#include <vector>
using namespace std;

int n, m;
int marble[301];

bool maxMarbleSum(int val)
{
	int cnt = 1, sum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (marble[i] > val)
		{
			return false;
		}

		if (sum + marble[i] <= val)
		{
			sum += marble[i];
		}

		else
		{
			++cnt;
			sum = marble[i];
		}
	}

	return cnt <= m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> marble[i];
	}
		
	int l = 1, r = n * 100;

	while (l <= r)
	{
		int mid = (l + r) / 2;

		if (maxMarbleSum(mid))
		{
			r = mid - 1;
		}

		else
		{
			l = mid + 1;
		}
	}

	cout << l << endl;

	//int cnt = 0, sum = 0, group = 1;
	//vector<int> ans;
	//for (int i = 0; i < n; ++i) {
	//	sum += marble[i];
	//	if (sum > l) {
	//		ans.push_back(cnt);
	//		sum = marble[i];
	//		cnt = 0;
	//		++group;
	//	}
	//	++cnt;
	//}
	//ans.push_back(cnt);
	//int pos = ans.size() - 1;
	//while (group < m) {
	//	if (ans[pos] == 1) {
	//		--pos;
	//	}
	//	else {
	//		--ans[pos];
	//		ans.push_back(1);
	//		++group;
	//	}
	//}
	//for (int val : ans) {
	//	cout << val << " ";
	//}

	return 0;
}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <limits.h>
//
//using namespace std;
//
//int N, M;
//int answer = INT_MAX;
//int ansmid = 0;
//vector<int> vecGoosle;
//
//int main()
//{
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++)
//	{
//		int nTemp;
//		cin >> nTemp;
//		vecGoosle.push_back(nTemp);
//	}
//
//	// 이분 탐색
//	int start = 0;
//	int end = 30000;
//
//	while (start < end)
//	{
//		int mid = (start + end) / 2; // 한 그룹의 최대 숫자의 합
//		int tempAnswer = 0;
//		int nTemp = 0;
//		int cnt = 0;
//
//		for (int i = 0; i < vecGoosle.size(); i++)
//		{
//			if (nTemp + vecGoosle[i] > mid)
//			{
//				bool bFlag = false;
//
//				if (nTemp == 0)
//				{
//					bFlag = true;
//					nTemp = vecGoosle[i];
//				}
//
//				cnt++;
//				tempAnswer = max(tempAnswer, nTemp);
//				nTemp = 0;
//
//				if (bFlag)
//				{
//					continue;
//				}
//
//				else
//				{
//					nTemp += vecGoosle[i];
//				}
//			}
//
//			else
//			{
//				nTemp += vecGoosle[i];
//			}
//		}
//
//		if (tempAnswer != 0)
//		{
//			tempAnswer = max(tempAnswer, nTemp);
//			cnt++;
//		}
//
//		if (cnt > M)
//		{
//			start = mid + 1;
//		}
//
//		else
//		{
//			if (cnt == M)
//			{
//				answer = min(answer, tempAnswer);
//
//				if (answer == tempAnswer)
//				{
//					ansmid = mid;
//				}
//			}
//
//			end = mid - 1;
//		}
//	}
//
//	cout << answer << '\n';
//
//	return 0;
//}
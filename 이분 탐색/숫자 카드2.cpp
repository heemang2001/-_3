#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	int nValue = 0;
	vector<int> NumberCard;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp = 0;

		cin >> nTemp;

		NumberCard.push_back(nTemp);
	}

	// Á¤·Ä
	sort(NumberCard.begin(), NumberCard.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int nTemp = 0;

		cin >> nTemp;

		int upper = upper_bound(NumberCard.begin(), NumberCard.end(), nTemp) - NumberCard.begin();
		int lower = lower_bound(NumberCard.begin(), NumberCard.end(), nTemp) - NumberCard.begin();

		nValue = upper - lower;

		cout << nValue << " ";		
	}
	

	return	0;
}

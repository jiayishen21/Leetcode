#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	int q;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int n, q;
		cin >> n;
		cin >> q;
		unordered_map<long, long> countMap;

		// # of segments a point is contained in is given by
		// # points to the left or equal * # points to the right or equal

		long x, k, prevX;
		if (n > 0)
		{
			cin >> prevX;
			countMap[n - 1]++;
		}
		for (int j = 1; j < n; j++)
		{
			cin >> x;

			countMap[j * (n - j) + (n - j - 1)] += 1;
			countMap[j * (n - j)] += x - prevX - 1;

			prevX = x;
		}
		for (int j = 0; j < q; j++)
		{
			cin >> k;

			if (countMap.find(k) != countMap.end())
			{
				cout << countMap[k] << " ";
			}
			else
			{
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
}

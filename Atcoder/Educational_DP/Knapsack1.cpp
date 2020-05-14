#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int W = 1e5;
const int N = 100;

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	int n, w, inp1, inp2;
	vector<pair<int, int>> arr;
	unsigned long long dp[N + 1][W + 1];
	cin >> n >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> inp1 >> inp2;
		arr.push_back({inp1, inp2});
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (j >= arr[i - 1].first)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i - 1].first] + arr[i - 1].second);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][w];
	return 0;
}
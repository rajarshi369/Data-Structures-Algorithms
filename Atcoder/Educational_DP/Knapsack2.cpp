#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int V = 1e5;
const int N = 100;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w, inp1, inp2, max_val = 0;
    vector<pair<int, int>> arr;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> inp1 >> inp2;
        arr.push_back({inp1, inp2});
        max_val += inp2;
    }
    unsigned long long dp[N + 1][V + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= max_val; j++)
        {
            dp[i][j] = LONG_MAX;
        }
    }
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= max_val; j++)
        {
            if (j == 0)
                dp[i][j] = 0;
            else if (j >= arr[i - 1].second)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - arr[i - 1].second] + arr[i - 1].first);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int res;
    for (int i = max_val; i >= 0; i--)
    {
        if (dp[n][i] <= w)
        {
            res = i;
            break;
        }
    }
    cout << res;
    return 0;
}
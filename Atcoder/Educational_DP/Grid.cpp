#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

#define ull unsigned long long
const int H = 1000;
const int W = 1000;
const ull mod = 1e9 + 7ULL;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w;
    string grid[H];
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> grid[i];
    ull dp[H][W];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            dp[i][j] = 0;
    }
    for (int i = 1; i < w; i++)
    {
        if (grid[0][i] == '#')
            break;
        dp[0][i] = 1ULL;
    }
    for (int i = 1; i < h; i++)
    {
        if (grid[i][0] == '#')
            break;
        dp[i][0] = 1ULL;
    }
    for (int i = 1; i < h; i++)
    {
        for (int j = 1; j < w; j++)
        {
            if (grid[i][j] == '.')
            {
                if (grid[i - 1][j] == '.')
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if (grid[i][j - 1] == '.')
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[h - 1][w - 1];
    return 0;
}
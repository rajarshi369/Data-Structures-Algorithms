#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

const int N = 2999;
long double h[N], t[N], p[N], dp[N + 1][N + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (i == 0)
        {
            h[i] = p[i], t[i] = 1.0 - p[i];
        }
        else
        {
            h[i] = h[i - 1] * p[i], t[i] = t[i - 1] * (1.0 - p[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)  
        {
            if (j > i)
                dp[i][j] = 0;
            else if (i == j)
                dp[i][j] = h[i - 1];
            else if (j == 0)
                dp[i][j] = t[i - 1];
            else
                dp[i][j] = p[i - 1] * dp[i - 1][j - 1] + (1.0 - p[i - 1]) * dp[i - 1][j];
        }
    }
    double ans = 0;
    for (int i = n / 2 + 1; i <= n; i++)
        ans += dp[n][i];
    cout << setprecision(9) << ans;
    return 0;
}
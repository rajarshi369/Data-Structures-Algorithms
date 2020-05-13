#include <iostream>
#include <algorithm>
const int LIMIT = 1e5;
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int arr[LIMIT];
    unsigned long long int dp[LIMIT];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, ULLONG_MAX, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = max(0, i - k); j < i; j++)
            dp[i] = min(abs(arr[i] - arr[j]) + dp[j], dp[i]);
    }
    cout << dp[n - 1];
    return 0;
}

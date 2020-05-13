#include <iostream>
#include <algorithm>
const int LIMIT = 1e5;
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[LIMIT];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int dp[LIMIT];
    dp[0] = 0, dp[1] = abs(arr[1] - arr[0]);
    for (int i = 2; i < n; i++)
        dp[i] = min(abs(arr[i] - arr[i - 2]) + dp[i - 2], abs(arr[i] - arr[i - 1]) + dp[i - 1]);
    cout << dp[n - 1];
    return 0;
}

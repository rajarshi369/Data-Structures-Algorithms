#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 1e5;

int main()
{
    int n, m, x, y;
    vector<int> adj[N + 1];
    int in[N];
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        in[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            q.push(i);
    }
    vector<int> order;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        order.push_back(x);
        for (auto i : adj[x])
        {
            in[i]--;
            if (in[i] == 0)
                q.push(i);
        }
    }
    unsigned long long maxLen[N + 1];
    unsigned long long maxDist = 0;
    for (int i = 0; i <= n; i++)
        maxLen[i] = 0;
    for (auto i : order)
    {
        for (auto j : adj[i])
        {
            maxLen[j] = max(maxLen[j], 1ULL + maxLen[i]);
        }
    }
    for (int i = 1; i <= n; i++)
        maxDist = max(maxDist, maxLen[i]);
    cout << maxDist;
    return 0;
}
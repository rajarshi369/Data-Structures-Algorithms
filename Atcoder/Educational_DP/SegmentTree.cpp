#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

const int N = 100000;
static int arr[N];
static int ST[2 * N + 2];

void buildTree(int index, int low, int high)
{ 
    if (low == high)
    {
      ST[index] = arr[low];
      return;
    }
    int mid = (low + high) / 2;
    buildTree(2 * index + 1, low, mid);
    buildTree(2 * index + 2, mid + 1, high);
    ST[index] = min(ST[2 * index + 1], ST[2 * index + 2]);
}
long query(int index, int ss, int se, int qs, int qe)
{
    if (qe < ss || qs > se)
      return INT_MAX;
    if (ss >= qs && se <= qe)
      return ST[index];
    int mid = (ss + se) / 2;
    return min(query(2 * index + 1, ss, mid, qs, qe), query(2 * index + 2, mid + 1, se, qs, qe));
}
int main()
{
    int n, q, L, R;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    buildTree(0, 0, n - 1);
    cin >> q;
    while (q--)
    {
      cin >> L >> R;
      cout << query(0, 0, n - 1, L, R) << endl;
    }
    return 0;
}
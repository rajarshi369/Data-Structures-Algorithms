#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5; //number of nodes

static int FT[2 * N];
static int S[N];
static int F[N];
static int timer = 0;

vector<int> adj[N];

void dfs(int node, int par){
    S[node] = timer;
    FT[timer++] = node;
    for(auto i : adj[node]){
        if(i != par)
            dfs(i, node);
    }
    F[node] = timer++; 
}

int main(){
    int n, m, x, y;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        adj[x - 1].push_back(y - 1), adj[y - 1].push_back(x - 1);
    }
    dfs(0, -1);
    for(int i = 0; i < 2 * n; i++)
        cout << FT[i] + 1 << " ";
}

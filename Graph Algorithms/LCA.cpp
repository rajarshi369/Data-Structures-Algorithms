#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>

using namespace std;

const int N = 1e5; //number of nodes

static int FT[2 * N];
static int S[N];
static int F[N];
static int lvl[N];
//static int parent[N];
static int timer = 0;
const int maxN = 17; // log2(N)
static int parent[N][maxN];

vector<int> adj[N];

void dfs(int node, int par, int level){
    S[node] = timer;
    FT[timer++] = node;
    lvl[node] = level;
    parent[node][0] = par;
    for(auto i : adj[node]){
        if(i != par)
            dfs(i, node, level + 1);
    }
    F[node] = timer;
    FT[timer++] = node; 
}

int lca(int a, int b){
    if(lvl[a] < lvl[b])
        swap(a, b);
    while(lvl[a] != lvl[b]){
        a = parent[a][0];
    }
    while(a != b){
        a = parent[a][0];
        b = parent[b][0];
    }
    return a;
}

int LCA(int a, int b){
    if(lvl[a] < lvl[b])
        swap(a, b);
    int d = lvl[a] - lvl[b];
    //cout << lvl[a] << " " << lvl[b] << " " << d << endl; 
    while(d > 0){
        //cout << "d = " << d << endl;
        int index = (int)log2(d);
        a = parent[a][index];
        d -= (1 << index);
        //cout << "d = " << d << " a = " << a + 1 << " index = " << index << endl;
    }
    //cout << "lvl[a] = " << lvl[a] << " lvl[b] = " << lvl[b] << endl;
    
    for(int i = 3; i >= 0; i--){
        if(a != b && parent[a][i] != -1)
            a = parent[a][i], b = parent[b][i];
    }
    /*while(a != b){
        a = parent[a][0];
        b = parent[b][0];
    }*/
    return a;
}


int main(){
    int n, m, x, y, q;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        adj[x - 1].push_back(y - 1), adj[y - 1].push_back(x - 1);
    }
    memset(parent, -1, sizeof parent);
    dfs(9, -1, 0);
    for(int i = 0; i < n; i++)
        cout << lvl[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << parent[i][0] << " ";
    cout << endl;
    cin >> q;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < 4; j++){
            if(parent[i][j - 1] != -1){
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << i + 1 << ":  ";
        for(int j = 0; j < 4; j++){
            cout << parent[i][j] + 1 << " ";
        }
        cout << endl;
    }
    while(q--){
        cin >> x >> y;
        cout << "LCA(" << x << "," << y <<") = " << lca(x - 1, y - 1) + 1 << endl;
        cout << "LCA(" << x << "," << y <<") = " << LCA(x - 1, y - 1) + 1 << endl;
        cout <<"\n";
    }
    return 0;
}


/*

10 9
10 1
10 2
1 4
1 5
2 6
2 7
5 3
5 9
6 8
8
1 3
2 5
6 8
4 2
10 8
2 9
1 10
8 7



*/
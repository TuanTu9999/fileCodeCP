#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int n, m, cnt;
vector<int> g[maxn];
bool vis[maxn];

void DFS(int u){
    vis[u] = 1;
    for(int i : g[u]){
        if(!vis[i]) DFS(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cnt++;
            DFS(i);
        }
    }
    cout << cnt;
    return 0;
}

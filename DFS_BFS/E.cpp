#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 3;

int n, m, S, ans;
bool vis[maxn];
vector<int> g[maxn];

void DFS(int u){
    vis[u] = 1;
    ans++;
    for(int x : g[u]){
        if(!vis[x]) DFS(x);
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
    cin >> n >> m >> S;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis[S] = 1;
    DFS(S);
    cout << ans;
    return 0;
}

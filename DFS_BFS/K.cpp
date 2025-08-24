#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 3;

int n, m, x, cnt;
vector<int> g[maxn];
bool vis[maxn];

void DFS(int u){
    vis[u] = 1;
    for(int pos : g[u]){
        if(!vis[pos]) DFS(pos);
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
    cin >> n >> m >> x;
    for(int i = 1; i <= m; i++){
        int a, b, c; cin >> a >> b >> c;
        if(c >= x){
            g[a].push_back(b);
            g[b].push_back(a);
        }
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

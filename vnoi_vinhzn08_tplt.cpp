#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
int n, m, cnt;
vector<int> g[maxn], ic[maxn];
bool vis[maxn];

void DFS(int u){
    vis[u] = 1;
    ic[cnt].push_back(u);
    for(int pos : g[u]){
        if(!vis[pos]){
            DFS(pos);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cnt++;
            DFS(i);
        }
    }
    cout << cnt << '\n';
    for(int i = 1; i <= cnt; i++){
        if(ic[i].size()){
            sort(ic[i].begin(), ic[i].end());
            cout << ic[i].size() << ' ';
            for(int x : ic[i]) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}

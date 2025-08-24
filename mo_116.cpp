#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
const int INF = 0x3f3f3f3f;

int n, m, dist[maxn];
vector<int> g[maxn];

void BFS(int u){
    memset(dist, 0x3f, sizeof dist);
    dist[u] = 0;
    queue<int> q;
    q.push(u);
    while(q.size()){
        u = q.front();
        q.pop();
        for(int v : g[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
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
    BFS(1);
    for(int i = 2; i <= n; i++)
        cout << ((dist[i] < INF) ? dist[i] : -1) << ' ';
    return 0;
}

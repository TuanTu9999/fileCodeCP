#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, m, k, dist[maxn], p[maxn];
vector<int> adj[maxn];

void BFS(int u) {
    queue<int> q;
    q.push(u);
    memset(dist, 0x3f, sizeof dist);
    dist[u] = 0;
    while(q.size()) {
        u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) cin >> p[i];
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(n);
    for(int i = 1; i <= k; i++) cout << dist[p[i]] << ' ';
    return 0;
}

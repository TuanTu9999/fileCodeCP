#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> g;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) cout << g[i].size() << '\n';
    return 0;
}

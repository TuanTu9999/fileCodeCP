#include <bits/stdc++.h>
#define veci vector<int>

using namespace std;

const int maxn = 1e5 + 3;
int n, m, cnt, a[maxn];
long long ans, tmp;
veci graph[maxn], com[maxn];
bool visited[maxn];

void DFS(int v){
    visited[v] = 1;
    com[cnt].push_back(v);

    for(int vertex : graph[v])
        if(!visited[vertex])
            DFS(vertex);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            DFS(i);
        }
    }
    for(int i = 1; i <= cnt; i++){
        tmp = 1e18;
        for(int x : com[i]) tmp = min(tmp, 1LL * a[x]);
        ans += tmp;
    }
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
#define veci vector<int>

using namespace std;

const int maxn = 1e5 + 3;
int n, m, cnt;
veci graph[maxn];
veci com[maxn];
bool visited[maxn];

void DFS(int v){
    visited[v] = 1;
    com[cnt].push_back(v);
    for(int x : graph[v]){
        if(!visited[x]) DFS(x);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
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
    cout << cnt << '\n';
    for(int i = 1; i <= cnt; i++){
        sort(com[i].begin(), com[i].end());
        cout << com[i].size() << ' ';
        for(int x : com[i]) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}

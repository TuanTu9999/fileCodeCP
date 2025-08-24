#include <bits/stdc++.h>
#define veci vector<int>

using namespace std;

const int maxn = 103;
int m, n, k, ans, cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[maxn][maxn];

void DFS(int u, int v){
    if(u > 0 && u <= m && v > 0 && v <= n){
        cnt++;
        visited[u][v] = 0;
        ans = max(ans, cnt);
        for(int i = 0; i < 4; i++){
            if(visited[u + dx[i]][v + dy[i]]) DFS(u + dx[i], v + dy[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++){
        int u, v; cin >> u >> v;
        visited[u][v] = 1;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(visited[i][j]){
                cnt = 0;
                DFS(i, j);
            }
        }
    }

    cout << ans;
    return 0;
}

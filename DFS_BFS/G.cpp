#include <bits/stdc++.h>
using namespace std;

const int maxn = 103;
const int INF = 0x3f3f3f3f;
char a[maxn][maxn];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int n, m, X, Y, dist[maxn][maxn];

void BFS(int x, int y){
    memset(dist, 0x3f, sizeof dist);
    dist[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(pair<int, int>(x, y));
    while(q.size()){
        x = (q.front()).first;
        y = (q.front()).second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int _x = x + dx[k];
            int _y = y + dy[k];
            if(_x > 0 && _x <= n && _y > 0 && _y <= m && a[_x][_y] != '*' && dist[_x][_y] > dist[x][y] + 1){
                dist[_x][_y] = dist[x][y] + 1;
                q.push(pair<int, int>(_x, _y));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'C'){
                X = i;
                Y = j;
            }
        }
    }
    BFS(X, Y);
    if (dist[1][1] != INF) cout << dist[1][1];
    else cout << -1;
    return 0;
}

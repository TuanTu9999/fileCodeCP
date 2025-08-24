#include <bits/stdc++.h>

using namespace std;

const int maxn = 1003;
const int INF = 0x3f3f3f3f;

int n, m, X1, Y1, X2, Y2, dist[maxn][maxn];
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

void BFS(int x, int y){
    memset(dist, 0x3f, sizeof dist);
    dist[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(pair<int, int>(x, y));
    while(q.size()){
        int x = (q.front()).first;
        int y = (q.front()).second;
        q.pop();
        for(int k = 0; k < 8; k++){
            int _x = x + dx[k], _y = y + dy[k];
            if(_x > 0 && _x <= n && _y > 0 && _y <= m && dist[_x][_y] > dist[x][y] + 1){
                dist[_x][_y] = dist[x][y] + 1;
                q.push(pair<int, int>(_x, _y));
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
    cin >> n >> m >> X1 >> Y1 >> X2 >> Y2;
    BFS(X1, Y1);
    if(dist[X2][Y2] != INF) cout << dist[X2][Y2];
    else cout << -1;
    return 0;
}

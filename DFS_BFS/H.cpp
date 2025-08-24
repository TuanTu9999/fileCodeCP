#include <bits/stdc++.h>

using namespace std;

const int maxn = 13;
const int INF = 0x3f3f3f3f;

int X, Y, S, T;
int dist[maxn][maxn];
int dx[] = {-2, 2, -2, 2};
int dy[] = {-2, -2, 2, 2};

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
              if(_x > 0 && _x <= 8 && _y > 0 && _y <= 8 && dist[_x][_y] > dist[x][y] + 1){
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
    cin >> X >> Y >> S >> T;
    BFS(X, Y);
    if(dist[S][T] != INF) cout << dist[S][T];
    else cout << -1;
    return 0;
}

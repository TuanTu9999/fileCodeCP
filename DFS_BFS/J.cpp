#include <bits/stdc++.h>

using namespace std;

const int maxn = 1003;
const int INF = 0x3f3f3f3f;

int n, m, k, p, dist[maxn][maxn];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
bool a[maxn][maxn];

void BFS(int x, int y){
    memset(dist, 0x3f, sizeof dist);
    dist[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(pair<int, int>(x, y));
    int len = 1;
    while(q.size()){
        x = (q.front()).first;
        y = (q.front()).second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int _x = x + dx[k], _y = y + dy[k];
            if(_x > 0 && _x <= n && _y > 0 && _y <= m && a[_x][_y] && dist[_x][_y] > dist[x][y] + 1){
                dist[_x][_y] = dist[x][y] + 1;
                q.push(pair<int, int>(_x, _y));
                len++;
                if(len == p - k) return;
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
    cin >> n >> m >> k;
    int PosX = 0, PosY = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j]){
                p++;
                PosX = i;
                PosY = j;
            }
        }
    }
    BFS(PosX, PosY);
    bool check = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] && dist[i][j] == INF){
                cout << i << ' ' << j << '\n';
                check = 0;
            }
        }
    }
    if(check) cout << "rotdoituyentinh";
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 103;

int n, a[maxn][maxn], ans = 1e9;
bool vis[maxn][maxn];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void loang(int x, int y, int l, int r){
    vis[x][y] = 1;
    for(int k = 0; k < 4; k++){
        int _x = x + dx[k], _y = y + dy[k];
        if(_x > 0 && _x <= n && _y > 0 && _y <= n && !vis[_x][_y] && a[_x][_y] >= l && a[_x][_y] <= r){
            loang(_x, _y, l, r);
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
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    for(int i = 0; i <= 100; i++){
        for(int j = i; j <= 100; j++){
            if(a[1][1] >= i && a[1][1] <= j){
                memset(vis, 0, sizeof vis);
                loang(1, 1, i, j);
                if(vis[n][n]){
                    ans = min(ans, j - i);
                }
            }
        }
    }
    cout << ans;
    return 0;
}

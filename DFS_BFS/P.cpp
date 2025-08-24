#include <bits/stdc++.h>

using namespace std;

const int maxn = 503;

int n, m, d[maxn][maxn], Ans, AnsCnt, ResCnt;
bool a[maxn][maxn], vis[maxn][maxn];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
pair<int, int> st;

void loang(int x, int y, int D){
    vis[x][y] = 1;
    if(a[x][y]) ResCnt++;
    for(int i = 0; i < 4; i++){
        int _x = x + dx[i], _y = y + dy[i];
        if(_x > 0 && _x <= n && _y > 0 && _y <= m &&
           !vis[_x][_y] && abs(d[_x][_y] - d[x][y]) <= D){
            loang(_x, _y, D);
        }
    }
}

bool check(int k){
    ResCnt = 0;
    memset(vis, 0, sizeof vis);
    loang(st.first, st.second, k);
    return (ResCnt == AnsCnt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> d[i][j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j]){
                st = pair<int, int>(i, j);
                AnsCnt++;
            }
        }
    }
    int l = 0, r = 1e9;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid)){
            Ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << Ans;
    return 0;
}

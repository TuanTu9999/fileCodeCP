#include <bits/stdc++.h>
using namespace std;

const int maxn = 8;
int n, m, a[maxn][maxn];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
bool v[maxn][maxn], br;

void backtrack(int x, int y, int k) {
    if(br) return;
    if(k == n * m) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) cout << a[i][j] << ' ';
            cout << '\n';
        }
        br = true;
        return;
    }

    for(int i = 0; i < 8; i++) {
        int _x = x + dx[i], _y = y + dy[i];
        if(_x > 0 && _x <= n && _y > 0 && _y <= m && !v[_x][_y]) {
            v[_x][_y] = true;
            a[_x][_y] = k + 1;
            backtrack(_x, _y, k + 1);
            if(br) return;
            v[_x][_y] = false;
            a[_x][_y] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            memset(v, 0, sizeof(v));
            memset(a, 0, sizeof(a));
            br = false;

            a[i][j] = 1;
            v[i][j] = true;
            backtrack(i, j, 1);

            if(br) break;
        }
        if(br) break;
    }
    return 0;
}

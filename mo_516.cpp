#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char a[7][7];
string tar;
bool check;

void backtrack(int k, int x, int y){
    if(k == (int)tar.size()){
        check = 1;
        return;
    }

    for(int pos = 0; pos < 4; pos++){
        int _x = x + dx[pos], _y = y + dy[pos];
        if(_x >= 0 && _x < n && _y >= 0 && _y < m && a[_x][_y] == tar[k])
            backtrack(k + 1, _x, _y);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    cin >> tar;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == tar[0]){
                backtrack(1, i, j);
                if(check){
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
    return 0;
}

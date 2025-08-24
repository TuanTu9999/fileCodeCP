#include <bits/stdc++.h>
#define llong            long long
#define el               cout << '\n'
#define pii              pair<int, int>
#define fi               first
#define se               second
#define veci             vector<int>
#define mapii            map<int, int>
#define pb               push_back

using namespace std;

const int maxn = 100 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, m, a[maxn][maxn], cnt, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void loang(int x, int y){
    a[x][y] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny]) loang(nx, ny);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char x; cin>>x;
            a[i][j] = (x == '#');
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j]){
                cnt++;
                loang(i, j);
            }
        }
    }
    cout<<cnt;
    return 0;
}

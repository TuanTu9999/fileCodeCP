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

const int maxn = 1000 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME "KHUDANCU"

int n, m, sum[maxn][maxn], d, k, ans;
char a[maxn][maxn];

int getsum(int x, int y){
    int bx = min(m, x + d), by = min(n, y + d), fx = max(0, x - d - 1), fy = max(0, y - d - 1);
    return sum[bx][by] - sum[bx][fy] - sum[fx][by] + sum[fx][fy];
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(FILENAME".INP", "r", stdin);
    freopen(FILENAME".OUT", "w", stdout);
    cin>>m>>n>>d>>k;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + (a[i][j] == 'M');
        }
    }
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(a[i][j] == 'P' && getsum(i, j) >= k) ans++;
    cout<<ans;
    return 0;
}

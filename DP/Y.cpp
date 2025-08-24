#include <bits/stdc++.h>

using namespace std;

const int maxn = 503;
int n, m, a[maxn][maxn], dp[maxn][maxn], ans = -3e8;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    for(int j = 1; j <= n; j++) dp[0][j] = dp[m + 1][j] = -2008;

    for(int j = 1; j <= n; j++)
        for(int i = 1; i <= m; i++)
            dp[i][j] = max({dp[i - 1][j - 1], dp[i][j - 1], dp[i + 1][j - 1]}) + a[i][j];


    for(int i = 1; i <= m; i++) ans = max(ans, dp[i][n]);
    cout << ans;
    return 0;
}

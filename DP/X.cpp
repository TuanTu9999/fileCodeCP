#include <bits/stdc++.h>

using namespace std;

const int maxn = 103;
int n, a[maxn][maxn], dp[maxn][maxn], ans = 1e9;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    for(int i = 1; i <= n; i++) dp[i][0] = dp[i][n + 1] = 2008;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]}) + a[i][j];

    for(int i = 1; i <= n; i++) ans = min(ans, dp[n][i]);
    cout << ans;
    return 0;
}

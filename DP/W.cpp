#include <bits/stdc++.h>

using namespace std;

const int maxn = 1003;
const int MOD = 1e9 + 7;
int n, m, dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char x; cin >> x;
            if(x == '.'){
                if(i == 1 && j == 1){
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][m];
    return 0;
}

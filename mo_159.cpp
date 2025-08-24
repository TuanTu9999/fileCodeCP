#include <bits/stdc++.h>

using namespace std;

const int maxn = 1003;
const int MOD = 1e9 + 7;

int n, k, a[maxn];
long long dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= min(i, k); j++){
            dp[i][j] = dp[i - 1][j]; // khong chon
            dp[i][j] = (dp[i][j] % MOD + (dp[i - 1][j - 1] * a[i]) % MOD) % MOD;
        }
    }
    cout << dp[n][k];
    return 0;
}

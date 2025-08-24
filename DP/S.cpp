#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
const int MOD = 1e9 + 7;
int n, k, dp[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = ((1LL * dp[i] + 2LL * dp[i - 1] + 1LL*MOD) % MOD);
        if(i - k - 1 >= 0)
            dp[i] = ((1LL * dp[i] - 1LL * dp[i - k - 1] + 1LL*MOD) % MOD);
        else if(i == k)
            dp[i] = ((1LL * dp[i] - 1LL + 1LL*MOD) % MOD);
        dp[i] %= MOD;
    }
    cout << dp[n];
    return 0;
}

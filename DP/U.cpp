#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
const int MOD = 1e9 + 7;
int n;
long long dp[3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    dp[0] = dp[1] = dp[2] = 1;
    for(int i = 2; i <= n; i++){
        long long tmp = dp[1];
        dp[1] = dp[0] + dp[2];
        dp[0] = dp[0] + tmp + dp[2];
        dp[2] = dp[0];
        dp[1] %= MOD;
        dp[2] %= MOD;
        dp[3] %= MOD;
    }
    cout << (dp[1] + dp[2] + dp[0]) % MOD;
    return 0;
}

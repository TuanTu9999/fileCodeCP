#include <bits/stdc++.h>

using namespace std;

const int maxn = 1003;
int n, k, a[maxn], w[maxn], v[maxn];
long long dp[maxn][4 * maxn + 100];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    k *= 1024;
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    for(int i = 1; i <= n; i++){
        for(int W = 1; W <= k; W++){
            if(W >= w[i]) dp[i][W] = max(dp[i - 1][W], dp[i - 1][W - w[i]] + v[i]);
            else dp[i][W] = dp[i - 1][W];
        }
    }
    cout << dp[n][k];
    return 0;
}

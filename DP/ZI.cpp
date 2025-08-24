#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 3;
int n, m, dp[maxn], a[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = a[i]; j <= m; j++){
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }
    cout << dp[m];
    return 0;
}

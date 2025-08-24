#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
int n, k, h[maxn], dp[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> h[i];
    memset(dp, 0x3f, sizeof dp);
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= min(i - 1, k); j++){
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    cout << dp[n];
    return 0;
}

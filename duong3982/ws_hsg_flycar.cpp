#include <bits/stdc++.h>

using namespace std;

const int maxn = 403;

int n, k, a[maxn];
long long dp[maxn][maxn], pre[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME "FLYCAR"
    if(fopen(FILENAME".INP", "r")){
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for(int i = 1, ma = -1e9; i <= n; i++){
        ma = max(ma, a[i]);
        dp[i][1] = 1LL * ma * i - pre[i];
    }
    k++;
    for(int x = 2; x <= k; x++){
        for(int i = 2; i <= n; i++){
            int ma = -1e9;
            dp[i][x] = 1e18;
            for(int j = i; j > 0; j--){
                ma = max(ma, a[j]);
                dp[i][x] = min(dp[i][x], dp[j - 1][x - 1] + 1LL * ma * (i - j + 1) - pre[i] + pre[j - 1]);
            }
        }
    }
    cout << dp[n][k];
    return 0;
}
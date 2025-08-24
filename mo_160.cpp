#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int n, a[maxn], b[maxn];
long long dp[maxn][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    for(int i = 2; i <= n; i++){
        dp[i][0] = max(dp[i - 1][1], dp[i - 2][1] + a[i - 1]) + a[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 2][0] + b[i - 1]) + b[i];
    }
    cout << max(dp[n][0], dp[n][1]);
    return 0;
}

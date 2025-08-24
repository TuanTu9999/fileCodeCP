#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
int n, a[maxn];
long long dp[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i < n; i++) cin >> a[i];
    dp[1] = 1e9;
    dp[2] = a[1];
    for(int i = 2; i <= n; i++){
        dp[i] = min(dp[i - 2], dp[i - 1]) + a[i - 1];
    }
    cout << dp[n];
    return 0;
}

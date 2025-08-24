#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
int n, a[maxn], b[maxn], dp[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) cin >> b[i];
    dp[1] = a[1];
    dp[2] = min(a[1] + a[2], b[1]);
    for(int i = 3; i <= n; i++)
        dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i - 1]);
    cout << dp[n];
    return 0;
}

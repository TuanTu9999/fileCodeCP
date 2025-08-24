#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 3;
int n, a[maxn], dp[maxn], ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        int j = lower_bound(dp + 1, dp + ans + 1, a[i]) - dp;
        ans = max(ans, j);
        dp[j] = a[i];
    }
    cout << ans;
    return 0;
}

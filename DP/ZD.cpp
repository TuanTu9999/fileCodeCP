#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
int n, ans = 1e9, sum, a[maxn];
bool dp[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = sum; j >= a[i]; j--){
            dp[j] |= dp[j - a[i]];
        }
    }
    for(int i = 1; i <= sum; i++){
        if(dp[i]) ans = min(ans, abs(sum - 2 * i));
    }
    cout << ans;
    return 0;
}

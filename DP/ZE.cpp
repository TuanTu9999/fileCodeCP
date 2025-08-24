#include <bits/stdc++.h>

using namespace std;

const int maxn = 103;
bool dp[maxn * maxn];
int n, a[maxn], sum, ans = -1e9;

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
        if(dp[i]) ans = max(ans, i * (sum - i));
    }
    cout << ans;
    return 0;
}

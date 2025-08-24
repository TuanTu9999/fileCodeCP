#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
const int MOD = 1e9 + 7;
int n, s, a[maxn], dp[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = 1;
    for(int j = 0; j <= s; j++){
        for(int i = 1; i <= n; i++){
            if(j >= a[i]){
                dp[j] += dp[j - a[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[s];
    return 0;
}

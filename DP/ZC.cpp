#include <bits/stdc++.h>

using namespace std;

const int maxn = 103;
const int MOD = 1e9 + 7;
int n, s, dp[1003];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> s;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        for(int j = s; j >= x; j--){
            dp[j] += dp[j - x];
            dp[j] %= MOD;
        }
    }
    cout << dp[s];
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
const int MOD = 14062008;
int n, m, a[maxn], dp[maxn];
bool b[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        b[x] = 1;
    }
    dp[1] = 1; dp[2] = (!b[2]);
    for(int i = 3; i <= n; i++){
        if(!b[i]){
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= MOD;
        }
    }
    cout << dp[n];
    return 0;
}

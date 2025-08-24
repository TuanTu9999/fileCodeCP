#include <bits/stdc++.h>

using namespace std;

const int maxn = 2003;
int n, l, h[maxn], w[maxn];
long long dp[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> l;
    for(int i = 1; i <= n; i++){
        cin >> h[i] >> w[i];
        int tmpL = 0, ma = 0;
        dp[i] = 1e18;
        for(int j = i; j > 0; j--){
            tmpL += w[j];
            if(tmpL > l) break;
            ma = max(ma, h[j]);
            dp[i] = min(dp[i], dp[j - 1] + ma);
        }
    }
    cout << dp[n];
    return 0;
}

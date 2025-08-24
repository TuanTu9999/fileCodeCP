#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 3;
int n, m, w[maxn], v[maxn], a[maxn];
long long dp[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i] >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= w[i]; j--){
            for(int t = 1; t <= a[i]; t++){
                if(j >= t * w[i]) dp[j] = max(dp[j], dp[j - t * w[i]] + 1LL * t * v[i]);
                else break;
            }
        }
    }
    cout << dp[m];
    return 0;
}

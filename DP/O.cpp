#include <bits/stdc++.h>

using namespace std;

const int maxn = 503;
int n, k, a[maxn];
long long dp[maxn];
/// dp[i]: cách chia mảng cho i phần tử đầu tiên sao cho tổng cái phần tử là max

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        int ma = -1e9;
        for(int j = i; j >= max(1, i - k + 1); j--){
            ma = max(ma, a[j]);
            dp[i] = max(dp[i], dp[j - 1] + 1LL * ma * (i - j + 1));
        }
    }
    cout << dp[n];
    return 0;
}

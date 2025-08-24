#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
const int MOD = 1e9 + 7;
int t, dp[maxn];
/// dp[i]: số cách lấp đầy hình chữ nhật có diện thích 2 * i

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= 1000000; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }
    cin >> t;
    while(t--){
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}

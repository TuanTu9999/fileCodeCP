#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, q, dp[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    for(int i = 1; i <= 1000000; i++){
        dp[i] = dp[i - 1] + 1;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                dp[i] = min(dp[i], dp[max(j, i / j)] + 1);
            }
        }
    }
    cin >> q;
    while(q--){
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}

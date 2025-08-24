#include <bits/stdc++.h>

using namespace std;

const int maxn = 1003;
const int MOD = 1e9 + 7;

int n, k, dp[maxn][maxn];
bool kt[2 * maxn], check[maxn][maxn];

void sieve(int Ln){
    kt[0] = kt[1] = 1;
    for(int i = 2; i * i <= Ln; i++){
        if(!kt[i]){
            for(int j = i * i; j <= Ln; j += i)
                kt[j] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    sieve(2000);
    cin >> n >> k;
    for(int i = 0; i <= k; i++) dp[1][i] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= k; j++){
            for(int f = 0; f <= k; f++){
                if(!kt[j + f]) (dp[i][j] += dp[i - 1][f]) %= MOD;
            }
        }
    }
    int Ans = 0;
    for(int i = 0; i <= k; i++) (Ans += dp[n][i]) %= MOD;
    cout << Ans;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e3 + 3;

int n, a[maxn], dp[maxn][maxn], Ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 3000; j++)
            dp[i][j] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j > 0; j--){
            if(a[i] > a[j])
                dp[i][a[i] - a[j]] = max(dp[i][a[i] - a[j]], dp[j][a[i] - a[j]] + 1);
            Ans = max(Ans, dp[i][a[i] - a[j]]);
        }
    }
    cout << Ans;
    return 0;
}

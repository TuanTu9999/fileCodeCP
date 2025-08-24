#include <bits/stdc++.h>

using namespace std;

const int maxn = 103;
int n, a[11], dp[11][10003], sum, ansV, ansP;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 1; i <= a[1]; i++) dp[1][i] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            for(int k = 1; k <= a[i]; k++){
                if(j - k >= 0) dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    for(int i = 1; i <= sum; i++){
        if(dp[n][i] > ansV){
            ansV = dp[n][i];
            ansP = i;
        }
    }
    cout << ansP;
    return 0;
}

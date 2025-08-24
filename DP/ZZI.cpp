#include <bits/stdc++.h>

using namespace std;

const int maxn = 2003;
string s, t;
int n, dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> s;
    t = s;
    reverse(s.begin(), s.end());
    n = s.size();
    t = ' ' + t;
    s = ' ' + s;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][n];
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
const int MOD = 1e9 + 7;

string s, t = " marisa";
int dp[7];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> s;
    int n = s.size(), m = 6;
    s = ' ' + s;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = m; j > 0; j--){
            if(s[i] == t[j]) (dp[j] += dp[j - 1]) %= MOD;
        }
    }
    cout <<  dp[m];
    return 0;
}

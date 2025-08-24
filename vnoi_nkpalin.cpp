#include <bits/stdc++.h>

using namespace std;

const int maxn = 2003;
int dp[maxn][maxn];
string s, t, ans;

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
    int n = s.size();
    s = ' ' + s;
    t = ' ' + t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = n, j = n;
    while(i > 0 && j > 0){
        if(s[i] == t[j]){
            ans += s[i];
            i--;
            j--;
        }
        else if(dp[i][j] == dp[i - 1][j]) i--;
        else j--;
    }
    for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
    return 0;
}

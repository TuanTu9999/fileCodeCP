#include <bits/stdc++.h>

using namespace std;

const int maxn = 510;

int n, a[maxn];
long long dp[maxn][maxn], pre[maxn], Ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    memset(dp, 0x3f, sizeof dp);
    for(int i = 0; i <= n; i++) dp[i][i] = 0;
    for(int i = 1; i < n; i++) dp[i][i + 1] = a[i] + a[i + 1];

    for(int i = n; i > 0; i--) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + pre[j] - pre[i - 1]);
            }
        }
    }

    cout << dp[1][n];
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, m, k, cnt[1000];
long long dp[1000][1000], v[1000][1000];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if (fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= k; j++) {
            int p = cnt[i] / (j + 1);
            int y = cnt[i] % (j + 1);
            int x = j + 1 - y;
            v[i][j] = 1LL * x * p * (p + 1) / 2 + 1LL * y * (p + 1) * (p + 2) / 2;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j] + v[i][0];
            for (int c = 1; c <= j; c++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - c] + v[i][c]);
            }
        }
    }

    cout << dp[m][k];
    return 0;
}

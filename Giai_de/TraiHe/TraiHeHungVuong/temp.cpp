/// hhoangcpascal

#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int dp[2006][2006], dph[2006][2006], dpv[2006][2006];
int n, m, q, a[2006][2006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j) {
        char c; cin >> c;
        a[i][j] = c - '0';

        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
        dph[i][j] = dph[i - 1][j] + dph[i][j - 1] - dph[i - 1][j - 1] + (a[i][j] & a[i][j - 1]);
        dpv[i][j] = dpv[i - 1][j] + dpv[i][j - 1] - dpv[i - 1][j - 1] + (a[i][j] & a[i - 1][j]);
    }

    while (q--) {
        int x, y, u, v; cin >> x >> y >> u >> v;

        int ans = dp[u][v] - dp[x - 1][v] - dp[u][y - 1] + dp[x - 1][y - 1];
        ans -= dph[u][v] - dph[x - 1][v] - dph[u][y] + dph[x - 1][y];
        ans -= dpv[u][v] - dpv[x][v] - dpv[u][y - 1] + dpv[x][y - 1];

        cout << ans << '\n';
    }

    return 0;
}
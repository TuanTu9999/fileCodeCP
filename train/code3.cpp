#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int addmod(long long a, long long b){ a += b; if (a >= MOD) a -= MOD; return (int)a; }
int mulmod(long long a, long long b){ return (int)((a * b) % MOD); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    string s; 
    if (!(cin >> s)) return 0;
    int n = (int)s.size();
    s = " " + s; // 1-index

    // dp[l][r] : số cách xóa hết s[l..r]
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // đoạn rỗng
    for (int i = 1; i <= n + 1; ++i) dp[i][i - 1] = 1;

    // duyệt theo độ dài
    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            if (len & 1) { dp[l][r] = 0; continue; } // độ dài lẻ -> không thể xóa hết

            long long ways = 0;
            for (int k = l + 1; k <= r; ++k) {
                if (s[k] == s[l]) {
                    ways += 1LL * dp[l + 1][k - 1] * dp[k + 1][r] % MOD;
                    if (ways >= MOD) ways -= MOD;
                }
            }
            dp[l][r] = (int)ways;
        }
    }

    cout << dp[1][n] << '\n';
    return 0;
}

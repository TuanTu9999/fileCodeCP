#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define COMP(x) x.resize(unique(all(x)) - x.begin())
template<typename T>
inline bool maximize(T &res, const T &val) {
    if (res < val) return res = val, 1;
    return 0;
}
template<typename T>
inline bool minimize(T &res, const T &val) {
    if (res > val) return res = val, 1;
    return 0;
}

using namespace std;

#define maxn ((int)15)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, cost[maxn][maxn], dp[maxn][1 << 12 | 1];

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1 << i] = 0;
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int sm = mask; sm; sm = (sm - 1) & mask) {
            for (int i = 0; i < n; i++) if (mask >> i & 1) {
                for (int j = 0; j < n; j++) if (sm >> j & 1) {
                    minimize(dp[i][mask], max(dp[i][mask ^ sm], dp[j][sm]) + cost[i][j]);
                }
            }
        }
    }

    cout << dp[0][(1 << n) - 1] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "SEND"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    int tt; cin >> tt;
    while (tt--) {
        process();
    }

    return 0;
}
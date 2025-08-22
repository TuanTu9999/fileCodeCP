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

#define maxn ((int)510)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = ((int)(1e9) + 7);
// #define ONLINE_JUDGE

inline void add(long long &cur, long long x) {
    cur += x;
    if (cur >= MOD) cur -= MOD;
}

int n, a[maxn];
long long dp[maxn][maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "CAU4"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) dp[i][a[i]] = 1;
    
    for (int i = 2; i <= n; i++) {
    for (int j = i - 1; j > 0; j--) if (a[j] < a[i]) {
        for (int k = 1; k <= 100; k++) {
            add(dp[i][__gcd(k, a[i])], dp[j][k]);
        }
    }
}
    // for (int i = 1; i <= n; i++) {
    //     for (int k = 0; k <= 3; k++) cout << dp[i][k] << ' ';
    //     cout << '\n';
    // }

    long long Ans = 0;
    for (int i = 1; i <= n; i++) add(Ans, dp[i][1]);
    cout << Ans;

    return 0;
}
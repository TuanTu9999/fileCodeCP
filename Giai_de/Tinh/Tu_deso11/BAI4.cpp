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

#define maxn ((int)(1e5) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = ((int)(1e9) + 7);
// #define ONLINE_JUDGE

long long memo[maxn];

bool process() {
    int s; cin >> s;
    for (int i = 1; i <= 50000; i++) {
        long long t = s - memo[i];
        if (t > 0 && binary_search(memo + 1, memo + 50001, t)) {
            return 1;
        }
    }
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "BAI4"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    for (int i = 1; i <= 50000; i++) {
        memo[i] = 1ll * i * (i + 1) / 2;
    }

    int tt; cin >> tt;
    while (tt--) {
        if (process()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
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
const int MOD = ((int)(1e9) + 696969);
// #define ONLINE_JUDGE

long long pw[maxn], hs[maxn];

long long getHash(int l, int r) {
    return ((hs[r] - hs[l - 1] * pw[r - l + 1]) % MOD + MOD) % MOD;
}

bool process() {
    string s; cin >> s;
    int n = s.size(); s = ' ' + s;
    if (n <= 1) return 0;
    if (n == 2) return s[1] == s[n];

    for (int i = 1; i <= n; i++) {
        hs[i] = (hs[i - 1] << 8) + s[i];
        hs[i] %= MOD;
    }

    if (n % 2 == 0) {
        if (getHash(1, n >> 1) == getHash((n >> 1) + 1, n)) return 1;
        return 0;
    }

    int mid = n >> 1;

    if (getHash(2, 2 + mid - 1) == getHash(2 + mid, n)) return 1;
    if (getHash(1, mid) == getHash(mid + 1, n - 1)) return 1;

    ++mid;
    for (int i = 2; i < n; i++) {
        long long hsL = 0, hsR = 0;
        if (i <= mid) {
            hsL = getHash(1, i - 1) * pw[mid - i] % MOD + getHash(i + 1, mid);
            hsL %= MOD;
            hsR = getHash(mid + 1, n);
        } else {
            hsL = getHash(1, mid - 1);
            hsR = getHash(mid, i - 1) * pw[n - i] % MOD + getHash(i + 1, n);
            hsR %= MOD;
        }

        if (hsL == hsR) return 1;
    }

    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "CAU3"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    int limPw = 1e5;
    pw[0] = 1;
    for (int i = 1; i <= limPw; i++) {
        pw[i] = (pw[i - 1] << 8) % MOD;
    }

    int tt; cin >> tt;
    while (tt--) {
        if (process()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
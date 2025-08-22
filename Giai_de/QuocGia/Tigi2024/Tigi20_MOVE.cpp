#include <bits/stdc++.h>

using namespace std;

const int maxn = 2010;
const int base = 1001;
const int MOD = 1e9 + 7;

template<typename type>
void add(type &cur, const type &x) {
    cur += x;
    if (cur >= MOD) cur -= MOD;
}
template<typename type>
void sub(type &cur, const type &x) {
    cur -= x;
    if (cur < 0) cur += MOD;
}
template<typename type>
void mul(type &cur, const type &x) {
    cur = 1ll * cur * x % MOD;
}

int n, k, x[maxn];
long long fact[maxn], ifact[maxn];

long long binPow(long long a, int b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

namespace sub1 {
    bool checkSub() {
        int sum = 0;
        for (int i = 1; i <= n; i++) sum += abs(x[i]);
        return sum == k;
    }

    void process() {
        long long Ans = fact[k];
        for (int i = 1; i <= n; i++) mul(Ans, ifact[abs(x[i])]);
        cout << Ans;
    }
}

namespace sub2 {
    bool checkSub() {
        return n == 1;
    }

    int dp[maxn][maxn];
    void process() {
        for (int i = 1; i <= n; i++) x[i] += base;
        dp[base][0] = 1;
        int lim = base << 1;
        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= lim; i++) {
                add(dp[i][j], dp[i][j - 1]);
                add(dp[i][j], dp[i - 1][j - 1]);
                add(dp[i][j], dp[i + 1][j - 1]);
            }
        }
        cout << dp[x[1]][k];
    }
}

namespace sub3 {
    long long dp[110][1010], d[1010][1010];

    long long C(int n, int k) {
        if (n < k || k < 0) return 0;
        return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
    }

    void process() {
        int lim = 0;
        for (int i = 1; i <= n; i++) {
            x[i] = abs(x[i]);
            lim = max(lim, x[i]);
        }
        for (int i = 0; i <= lim; i++) { 
            for (int j = 0; j <= k; j++) {
                if ((i & 1) != (j & 1)) continue;
                d[i][j] = C(j, (i + j) >> 1);
            }
        }

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int q = 0; q <= j; q++) {
                    add(dp[i][j], dp[i - 1][j - q] * d[x[i]][q] % MOD * C(j, q) % MOD);
                }
            }
        }

        long long Ans = 0;
        for (int j = 0; j <= k; j++) {
            add(Ans, dp[n][j] * C(k, j) % MOD);
        }

        cout << Ans;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define filename "MOVE"
    if (fopen(filename".inp", "r")) {
        freopen(filename".inp", "r", stdin);
        freopen(filename".out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> x[i];
    fact[0] = 1;
    for (int i = 1; i <= 2000; i++) fact[i] = fact[i - 1] * i % MOD;
    ifact[2000] = binPow(fact[2000], MOD - 2);
    for (int i = 1999; i >= 0; i--) ifact[i] = ifact[i + 1] * (i + 1) % MOD;

    // if (sub1::checkSub()) sub1::process();
    // else if (sub2::checkSub()) sub2::process();
    // else sub3::process();

    sub3::process();

    return 0;
}
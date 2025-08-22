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

#define maxn ((int)(7e4) + 10)
#define LOG(x) (int)(31 - __builtin_clz(x))
const int MOD = ((int)(1e9) + 7);
// #define ONLINE_JUDGE

int n, w, h;
array<int, 3> a[maxn];

namespace sub1 {
    inline bool checkSub() {
        return n == 0;
    }

    void process() {
        int res = -1;
        if (h == 0) res = w;
        else if (w == 0) res = h;
        else if (h == w) res = h;

        cout << res;
    }
}

namespace sub2 {
    inline bool checkSub() {
        return h == 0 && n <= 200;
    }

    int dp[300][36];
    void process() {
        a[++n] = {w, h};
        sort(a + 1, a + n + 1, [&](const array<int, 3> &x, const array<int, 3> &y) {
            if (x[0] == y[0]) return x[1] < y[1];
            return x[0] < y[0];
        });

        memset(dp, 0x3f, sizeof dp);
        dp[1][0] = a[1][0];
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int d = 0; d <= LOG(w); d++) {
                    int dist = (a[j][0] - a[i][0]);                        
                    if (dist % (1 << d) == 0) minimize(dp[j][d], dp[i][d] + dist / (1 << d));
                    if (dist % (1 << d + 1) == 0) minimize(dp[j][d + 1], dp[i][d] + dist / (1 << d + 1));
                    minimize(dp[j][0], dp[i][d] + dist);
                    if (d > 0 && dist % (1 << (d - 1)) == 0)
                        minimize(dp[j][d - 1], dp[i][d] + dist / (1 << (d - 1)));
                }
            }
        }

        int Ans = 1e9 + 1;
        for (int i = 0; i <= LOG(w); i++) {
            minimize(Ans, dp[n][i]);
        }
        if (Ans == (int)1e9 + 1) cout << -1 << '\n';
        else cout << Ans;
    }
}

namespace sub3 {
    inline bool checkSub() {
        return h == 0;
    }

    int dp[maxn][36], nex[maxn][36];
    void process() {
        a[++n] = {w, h};
        sort(a + 1, a + n + 1, [&](const array<int, 3> &x, const array<int, 3> &y) {
            if (x[0] == y[0]) return x[1] < y[1];
            return x[0] < y[0];
        });

        for (int d = 0; d <= 30; d++) {
            int k = 1 << d;
            unordered_map<int, int> cur;
            for (int i = n; i > 0; i--) {
                int f = a[i][0] % k;
                if (cur.count(f)) {
                    nex[i][d] = cur[f];
                }
                cur[f] = i;
            }
        }

        memset(dp, 0x3f, sizeof dp);
        dp[1][0] = a[1][0];
        for (int i = 1; i <= n; i++) {
            for (int d = 0; d <= 30; d++) {
                int j = nex[i][0];
                int dist = (a[j][0] - a[i][0]);  
                minimize(dp[j][0], dp[i][d] + dist);

                j = nex[i][d];
                dist = (a[j][0] - a[i][0]);                        
                if (dist % (1 << d) == 0) minimize(dp[j][d], dp[i][d] + dist / (1 << d));

                j = nex[i][d + 1];
                dist = (a[j][0] - a[i][0]);
                if (dist % (1 << d + 1) == 0) minimize(dp[j][d + 1], dp[i][d] + dist / (1 << d + 1));

                if (d) {
                    j = nex[i][d - 1];
                    dist = (a[j][0] - a[i][0]);
                    if (dist % (1 << (d - 1)) == 0)
                        minimize(dp[j][d - 1], dp[i][d] + dist / (1 << (d - 1)));
                }
            }
        }

        int Ans = (int)1e9 + 1;
        for (int i = 0; i <= 30; i++) minimize(Ans, dp[n][i]);
        if (Ans != (int)1e9 + 1) cout << Ans;
        else cout << -1;
    }
}

namespace sub45 {
    int dp[maxn][36][3], nex[maxn][36][3];

    void process() {
        a[++n] = {w, h};
        sort(a + 1, a + n + 1, [&](const array<int, 3> &x, const array<int, 3> &y) {
            if (x[0] == y[0]) return x[1] < y[1];
            return x[0] < y[0];
        });

        for (int k = 0; k < 2; k++) {
            for (int d = 0; d <= 30; d++) {
                int k = 1 << d;
                unordered_map<int, int> cur;
                for (int i = n; i > 0; i--) {
                    int f;
                    if (k == 0) f = a[i][0] % k;
                    else f = a[i][1] % k;
                    if (cur.count(f)) {
                        nex[i][d][k] = cur[f];
                    }
                    cur[f] = i;
                }
            }
        }
        for (int d = 0; d <= 30; d++) {
            int k = 1 << d;
            map<pii, int> cur;
            for (int i = n; i > 0; i--) {
                pii f = {a[i][0] % d, a[i][1] % d};
                if (cur.count(f)) {
                    nex[i][d][2] = cur[f];
                }
                cur[f] = i;
            }
        }

        memset(dp, 0x3f, sizeof dp);
        for (int i = 1; i <= n; i++) {
            if (a[i][1] == 0) dp[i][0][0] = a[i][0];
            else if (a[i][0] == 0) dp[i][0][1] = a[i][1];
            else if (a[i][0] == a[i][1]) dp[i][0][2] = a[i][0];
        }
        for (int i = 1; i <= n; i++) {
            for (int d = 0; d <= 30; d++) {
                for (int k = 0; k < 3; k++) {
                    for (int nk = 0; nk < 3; nk++) {
                        int j = nex[i][0][nk];
                        int dist = (a[j][nk] - a[i][k]);  
                        minimize(dp[j][0][nk], dp[i][d][k] + dist);

                        j = nex[i][d][k];
                        dist = (a[j][0] - a[i][0]);                        
                        if (dist % (1 << d) == 0) minimize(dp[j][d][nk], dp[i][d][k] + dist / (1 << d));

                        j = nex[i][d + 1][nk];
                        dist = (a[j][0] - a[i][0]);
                        if (dist % (1 << d + 1) == 0) minimize(dp[j][d + 1][nk], dp[i][d][k] + dist / (1 << d + 1));

                        if (d) {
                            j = nex[i][d - 1][nk];
                            dist = (a[j][0] - a[i][0]);
                            if (dist % (1 << (d - 1)) == 0)
                                minimize(dp[j][d - 1][nk], dp[i][d][k] + dist / (1 << (d - 1)));
                        }
                    }
                }
            }
        }

        int Ans = (int)1e9 + 1;
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i <= 30; i++) {
                minimize(Ans, dp[n][i][k]);
            }
        }

        if (Ans != (int)1e9 + 1) cout << Ans;
        else cout << -1;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n >> w >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
        if (a[i][0] == a[i][1]) a[i][2] = a[i][1];
    }

    if (sub1::checkSub()) sub1::process();
    else if (sub2::checkSub()) sub2::process();
    else if (sub3::checkSub()) sub3::process();
    else sub45::process();
    
    return 0;
}

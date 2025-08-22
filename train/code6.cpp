#include <bits/stdc++.h>
#define debug(a) cerr << (a) << ' '
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define MASK(x) ((1LL) << (x))
#define BIT(x, i) (((x) >> (i)) & (1LL))
#define eb emplace_back
#define pb push_back

// #pragma GCC             optimize("Ofast")
// #pragma GCC             optimize("O3")
// #pragma GCC             optimize("unroll-loops")
// #pragma GCC             target("avx,avx2,fma")

using namespace std;

template<typename T>
bool maximize(T &res, const T &val) {
    if (res < val) {
        res = val;
        return 1;
    }
    return 0;
}

template<typename T>
bool minimize(T &res, const T &val) {
    if (res > val) {
        res = val;
        return 1;
    }
    return 0;
}

const int maxn = 110;
const int MOD = 1e9 + 7;
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define LOG 20

int n;
struct Data {
    int a, b, c, d, w;
} a[maxn];

namespace sub1 {
    bool check() {
        return n <= 20;
    }

    int chose[30], sz, tree[maxn][5];

    void update(int pos, int x, int val) {
        for (int i = pos; i <= n + 2; i += i & -i) tree[i][x] = max(tree[i][x], val);
    }
    int get(int pos, int x) {
        int res = 0;
        for (int i = pos; i > 0; i -= i & -i) maximize(res, tree[i][x]);
        return res;
    }

    int process() {
        int Ans = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            sz = 0;
            for (int j = 0; j < n; j++) if (mask >> j & 1) chose[++sz] = j + 1;

            int dp[30][5];
            memset(dp, 0, sizeof dp);
            memset(tree, 0, sizeof tree);
            dp[1][a[chose[1]].a] = a[chose[1]].w;
            dp[1][a[chose[1]].b] = a[chose[1]].w;
            dp[1][a[chose[1]].c] = a[chose[1]].w;
            dp[1][a[chose[1]].d] = a[chose[1]].w;

            update(2, a[chose[1]].a, a[chose[1]].w);
            update(2, a[chose[1]].b, a[chose[1]].w);
            update(2, a[chose[1]].c, a[chose[1]].w);
            update(2, a[chose[1]].d, a[chose[1]].w);

            for (int idx = 2; idx <= sz; idx++) {
                int i = chose[idx];

                dp[idx][a[i].a] = max(get(idx, a[i].a), get(idx, a[i].c)) + a[i].w;
                dp[idx][a[i].b] = max(get(idx, a[i].b), get(idx, a[i].d)) + a[i].w;
                dp[idx][a[i].c] = max(get(idx, a[i].c), get(idx, a[i].a)) + a[i].w;
                dp[idx][a[i].d] = max(get(idx, a[i].d), get(idx, a[i].b)) + a[i].w;

                update(idx + 1, a[i].a, dp[idx][a[i].a]);
                update(idx + 1, a[i].b, dp[idx][a[i].b]);
                update(idx + 1, a[i].c, dp[idx][a[i].c]);
                update(idx + 1, a[i].d, dp[idx][a[i].d]);
                Ans = max({Ans, dp[idx][a[i].a], dp[idx][a[i].b], dp[idx][a[i].c], dp[idx][a[i].d]});
            }
            // for (int idx = 1; idx <= sz; idx++) {
            //     cerr << "#" << idx << ":\n";
            //     cerr << dp[idx][0] << '\n';
            //     cerr << dp[idx][1] << '\n';
            //     cerr << dp[idx][2] << '\n';
            //     cerr << dp[idx][3] << '\n';
            //     cerr << '\n';
            // }
        } 
        return Ans;
    }
}


signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "INOUT"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d >> a[i].w;

    cout << sub1::process();

    return 0;
}
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

const int maxn = 1e5 + 10;
const int MOD = 1e9 + 7;
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define LOG 20

int n, sz[maxn];
vector<pii> adj[maxn];
long long dp[maxn], dpr[maxn];

void dfs(int u, int p) {
    sz[u] = 1;
    for (const auto &[v, w] : adj[u]) if (v != p) {
        dfs(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v] + 1ll * w * sz[v];
    }
}

void reroot(int u, int p) {
    for (const auto &[v, w] : adj[u]) if (v != p) {
        dpr[v] = dp[u] + 1ll * w * (n - 2 * sz[v]);
        reroot(v, u);
    }
}

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "MEOMAN1"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
    }

    dfs(1, 0);
    dpr[1] = dp[1];
    reroot(1, 0);

    long long Ans = 1e18;
    for (int i = 1; i <= n; i++) {
        Ans = min(Ans, dpr[i]);
    }

    cout << Ans;

    return 0;
}
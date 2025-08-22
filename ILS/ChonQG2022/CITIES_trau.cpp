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

const int maxn = 2e5 + 10;
const int MOD = 1e9 + 7;
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define LOG 20

int n, m, sz[maxn], p[maxn], cnt;
vector<int> adj[maxn];
pii edge[maxn];
bool vis[maxn];

void dfs(int u) {
    vis[u] = 1;
    sz[cnt]++;
    p[u] = cnt;
    for (int v : adj[u]) if (!vis[v]) {
        dfs(v);
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

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        edge[i] = {x, y};
    }

    int tt; cin >> tt;
    while (tt--) {
        int u, k; cin >> u >> k;
        vector<int> cur(k);
        for (int &x : cur) cin >> x;

        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= m; i++) if (edge[i].first != u && edge[i].second != u) {
            int x = edge[i].first, y = edge[i].second;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        memset(vis, 0, sizeof vis);
        memset(p, 0, sizeof p);
        memset(sz, 0, sizeof sz);
        cnt = 0;
        for (int i = 1; i <= n; i++) if (!vis[i]) {
            cnt++;
            dfs(i);
        }

        bool yes = 1;
        int tar = p[cur.back()];
        for (int x : cur) {
            if (p[x] != tar) {
                yes = 0;
                break;
            }
        }

        if (yes && sz[tar] > k) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
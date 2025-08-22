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

int n, m, sz[maxn], scc[maxn], id[maxn], low[maxn], cntScc;
vector<int> adj[maxn], st;
bool flag[maxn];

int timeDFS;
void dfs(int u, int p) {
    id[u] = low[u] = ++timeDFS;
    st.push_back(u);
    
    int child = 0;
    for (int v : adj[u]) if (v != p) {
        if (id[v]) {
            low[u] = min(low[u], id[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }

        if (p != -1 && low[v] >= id[u]) flag[u] = 1; 
    }

    if (p == -1 && child > 1) flag[u] = 1;

    if (id[u] == low[u]) {
        cntScc++;
        while (1) {
            int v = st.back();
            st.pop_back();
            scc[v] = cntScc;
            if (u == v) break;
        }
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
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) sort(all(adj[i]));

    dfs(1, -1);
    for (int i = 1; i <= n; i++) if (flag[i]) sz[scc[i]]++;

    int tt; cin >> tt;
    while (tt--) {
        int u, k; cin >> u >> k;
        vector<int> cur(k);
        for (int &x : cur) cin >> x;

        bool check1 = 0, check2 = 1;
        for (int x : cur) {
            if (scc[x] != scc[u]) {
                check1 = 0;
            } 
            if (binary_search(all(adj[u]), x)) {
                check2 = 1;
            }
        }

        cerr << check1 << ' ' << check2 << ' ' << flag[u] << ' ' << sz[scc[u]] << '\n';
        if (flag[u] && (check2 || (check1 && sz[scc[u]] == 1))) cout << "No\n";
        else cout << "Yes\n";
    }

    // for (int i = 1; i <= n; i++) cout << scc[i] << ' ';

    return 0;
}
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

#define maxn ((int)(2e5) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, a[maxn];
vector<int> adj[maxn];
long long dpin[maxn], dpout[maxn], sum[maxn], S;

void dfsin(int u, int p) {
    sum[u] = a[u];
    for (int v : adj[u]) if (v ^ p) {
        dfsin(v, u);
        sum[u] += sum[v];
        dpin[u] += dpin[v] + sum[v];
    }
}

void dfsout(int u, int p) {
    for (int v : adj[u]) if (v ^ p) {
        dpout[v] = dpout[u] + (dpin[u] - dpin[v]) + (S - 2ll * sum[v]);
        dfsout(v, u);
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

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S += a[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    dfsin(1, 0);
    dfsout(1, 0);

    long long Ans = -1e18;
    for (int i = 1; i <= n; i++)
        maximize(Ans, dpin[i] + dpout[i]);

    cout << Ans;

    return 0;
}

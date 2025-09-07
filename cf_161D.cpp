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

#define maxn ((int)50010)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, k;
vector<int> adj[maxn];
int dpin[maxn][510], dpout[maxn][510];

void dfsin(int u, int p) {
    dpin[u][0] = 1;
    for (int v : adj[u]) if (v ^ p) {
        dfsin(v, u);

        for (int i = 1; i <= k; i++) {
            dpin[u][i] += dpin[v][i - 1];
        }
    }
}

void dfsout(int u, int p) {
    dpout[u][0] = 1;
    for (int i = 1; i <= k; i++) {
        dpout[u][i] += dpout[p][i - 1];
    }

    vector<int> cur(k + 1, 0);
    for (int v : adj[u]) if (v ^ p) {
        for (int i = 1; i <= k; i++) {
            cur[i] += dpin[v][i - 1];
        }
    }

    for (int v : adj[u]) if (v ^ p) {
        for (int i = 2; i <= k; i++) {
            dpout[v][i] += cur[i - 1] - dpin[v][i - 2];
        }
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

    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    dfsin(1, 0);
    dfsout(1, 0);

    long long Ans = 0;
    for (int i = 1; i <= n; i++) {
        Ans = Ans + dpin[i][k] + dpout[i][k];
    }

    cout << Ans / 2;

    return 0;
}

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

const int maxn = 1e6 + 10;
const int MOD = 1e9 + 7;
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define LOG 20

char a[20][20];
int dp[16][1 << 15 | 1], dist[15][15];
int n, m;
vector<pii> pos;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void bfs(int u, int v, int curPos) {
    queue<pii> q;
    int D[15][15];
    memset(D, 0x3f, sizeof D);

    D[u][v] = 0;
    q.emplace(u, v);

    while (!q.empty()) {
        pii current = q.front();
        q.pop();
        int u = current.first;
        int v = current.second;

        for (int i = 0; i < 4; i++) {
            int nu = u + dx[i];
            int nv = v + dy[i];

            if (nu < 0 || nu >= n || nv < 0 || nv >= m) continue;
            if (a[nu][nv] == 'x') continue;

            if (D[nu][nv] > D[u][v] + 1) {
                D[nu][nv] = D[u][v] + 1;
                q.emplace(nu, nv);
            }
        }
    }

    for (int i = 0; i < pos.size(); i++) {
        dist[curPos][i] = D[pos[i].first][pos[i].second];
    }
}

void process() {
    pos.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (a[i][j] == 'o' || a[i][j] == '*') {
            pos.emplace_back(i, j);
            // cerr << i << ' ' << j << ' ' << cnt << '\n';
        }
    }

    for (int i = 0; i < pos.size(); i++) {
        bfs(pos[i].first, pos[i].second, i);
    }

    for (int mask = 1; mask < (1 << pos.size()); mask++) {
        int i = 31 - __builtin_clz(mask); 
        if (a[pos[i].first][pos[i].second] != 'o' || (mask ^ (1 << i))) dp[i][mask] = inf;
        else dp[i][mask] = 0;
        for (int j = 0; j < pos.size(); j++) if (i != j && (mask & (1 << j))) {
            minimize(dp[i][mask], dp[j][mask ^ (1 << i)] + dist[j][i]);
        }
    }

    int Ans = inf;
    for (int i = 0; i < pos.size(); i++) {
        minimize(Ans, dp[i][(1 << pos.size()) - 1]);
    }
    if (Ans == inf) cout << -1;
    else cout << Ans;
    cout << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME "INOUT"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }

    while (1) {
        cin >> m >> n;
        if (n == 0 && m == 0) break;
        process();
    }

    return 0;
}
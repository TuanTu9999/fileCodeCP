#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int n, m, a[maxn], b[maxn];

struct segtri {
    vector<int> tree;
    int n;
    segtri(int sz) : n(sz), tree(sz << 2, 1e9) {}

    void p_update(int pos, int val, int id, int l, int r) {
        if (pos < l || r < pos) return;
        if (l == r) {
            tree[id] = val;
            return;
        }
        int mid = l + r >> 1;
        p_update(pos, val, id << 1, l, mid);
        p_update(pos, val, id << 1 | 1, mid + 1, r);
        tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
    }

    int p_get(int st, int en, int id, int l, int r) {
        if (en < l || r < st) return 1e9;
        if (st <= l && r <= en) return tree[id];

        int mid = l + r >> 1;

        return min(p_get(st, en, id << 1, l, mid),
                   p_get(st, en, id << 1 | 1, mid + 1, r));
    }

    void update(int pos, int val) {
        p_update(pos, val, 1, 1, n);
    }
    int get(int st, int en) {
        return p_get(st, en, 1, 1, n);
    }
};

namespace sub1 {
    bool checkSub() {
        return n <= 100 && m <= 100;
    }

    void process() {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));
        for (int i = b[1] - a[1] + 1; i <= n; i++) {
            dp[1][i] = abs(i - b[1]);
        }

        for (int i = 2; i <= m; i++) {
            int prelen = b[i - 1] - a[i - 1] + 1;
            int len = b[i] - a[i] + 1;
            for (int j = len; j <= n; j++) {
                for (int k = max(1, j - len + 1); k <= min(n, j + prelen - 1); k++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(b[i] - j));
                }
            }
        }

        // for (int i = 1; i <= m; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cerr << dp[i][j] << ' ';
        //     }
        //     cerr << '\n';
        // }

        int Ans = 1e9;
        for (int j = a[m]; j <= n; j++) {
            Ans = min(Ans, dp[m][j]);
        }

        cout << Ans << '\n';
    }
}

namespace sub2 {
    void process() {
        segtri it(n + 1);
        for (int i = b[1] - a[1] + 1; i <= n; i++) {
            it.update(i, abs(i - b[1]));
        }
        for (int i = 2; i <= m; i++) {
            vector<int> dp(n + 1, 1e9);
            int len = b[i] - a[i] + 1;
            int prelen = b[i - 1] - a[i - 1] + 1;

            for (int j = len; j <= n; j++) {
                dp[j] = min(dp[j], it.get(max(1, j - len + 1), min(n, j + prelen - 1)) + abs(b[i] - j));
            }

            for (int j = 1; j <= n; j++) {
                it.update(j, dp[j]);
            }
        }
        cout << it.get(1, n) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #define filename "BPICTURE"
    if (fopen(filename".inp", "r")) {
        freopen(filename".inp", "r", stdin);
        freopen(filename".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];

    sub2::process();

    return 0;
}
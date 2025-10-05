#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int n;
int x[maxn], y[maxn];
int comp[maxn << 1];

struct SegmentTree {
    vector<int> tree;
    int n;
    SegmentTree(int n) : n(n) {
        tree.resize(n << 2, -1e9);
    }

    void processUpdate(int pos, int val, int id, int l, int r) {
        if (pos < l || r < pos) return;
        if (l == r) {
            tree[id] = max(tree[id], val);
            return;
        }
        int mid = l + r >> 1;
        processUpdate(pos, val, id << 1, l, mid);
        processUpdate(pos, val, id << 1 | 1, mid + 1, r);
        tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
    }
    int processGet(int st, int en, int id, int l, int r) {
        if (en < l || r < st) return -1e9;
        if (st <= l && r <= en) return tree[id];
        int mid = l + r >> 1;
        return max(processGet(st, en, id << 1, l, mid),
                   processGet(st, en, id << 1 | 1, mid + 1, r));
    }

    void update(int pos, int val) {
        processUpdate(pos, val, 1, 1, n);
    }
    int get(int st, int en) {
        return processGet(st, en, 1, 1, n);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        comp[++comp[0]] = x[i] - 1;
        comp[++comp[0]] = x[i];
        comp[++comp[0]] = x[i] + y[i];
        comp[++comp[0]] = x[i] + y[i] - 1;
        y[i] = x[i] + y[i];
    }

    comp[++comp[0]] = 0;
    sort(comp + 1, comp + comp[0] + 1);
    comp[0] = unique(comp + 1, comp + comp[0] + 1) - comp - 1;

    for (int i = 1; i <= n; i++) {
        x[i] = lower_bound(comp + 1, comp + comp[0] + 1, x[i]) - comp;
        y[i] = lower_bound(comp + 1, comp + comp[0] + 1, y[i]) - comp; 
    }

    SegmentTree st1(comp[0]), st2(comp[0]);

    st1.update(1, 0);
    st2.update(1, 0);
    for (int i = 1; i <= n; i++) {
        int dp = st1.get(1, x[i] - 1) + (comp[y[i]] - comp[x[i]]);
        dp = max(dp, st2.get(x[i], y[i] - 1) + comp[y[i]] - 1);
        st1.update(y[i], dp);
        st2.update(y[i], dp - comp[y[i] - 1]);
    }

    cout << st1.tree[1];

    return 0;    
}

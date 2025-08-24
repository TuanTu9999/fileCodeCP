#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;

int n, k, a[maxn], tree[maxn << 1 << 1];
long long Ans;
map<int, vector<int>> pos;

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || r < pos) return;
    if (l == r) {
        tree[id] = val;
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, pos, val);
    update(id << 1 | 1, mid + 1, r, pos, val);
    tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
}

int getMin(int id, int l, int r, int be, int en) {
    if (en < l || r < be) return 1'000'000'000;
    if (be <= l && r <= en) return tree[id];
    int mid = l + r >> 1;
    return min(getMin(id << 1, l, mid, be, en),
               getMin(id << 1 | 1, mid + 1, r, be, en));
}

long long bs(int x, int R) {
    vector<int>& temp = pos[x];
    if (temp.empty()) return 0;
    int l = 0, r = temp.size() - 1, res = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (temp[mid] + 1 <= R && getMin(1, 1, n, temp[mid] + 1, R) >= x) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    int tttt = upper_bound(temp.begin(), temp.end(), R) - temp.begin() - 1;
    if (tttt >= 0) return (temp[tttt] - temp[res] + 1);
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if (fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }

    cin >> n >> k;
    memset(tree, 0x3f, sizeof tree);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        pos[a[i]].push_back(i);
        update(1, 1, n, i, a[i]);
    }

    int i = 2;
    long long val;
    while (i <= n) {
        if (i != 2 && a[i] == a[i - 1]) Ans += val;
        else {
            val = bs(a[i] - k, i);
            Ans += val;
        }
        i++;
    }

    cout << Ans;

    return 0;
}

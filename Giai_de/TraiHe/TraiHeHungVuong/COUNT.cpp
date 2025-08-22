#include <bits/stdc++.h>

using namespace std;

#define maxn ((int)(1e5) + 10)

int n, k, a[maxn];

// Cây Segment Tree cho bài toán: Range Add / Range Sum
struct Node {
    long long sum;
    long long lazy;
} tree[maxn << 2];

void push_down(int id, int l, int r) {
    if (tree[id].lazy == 0) return;
    long long val = tree[id].lazy;

    int mid = (l + r) / 2;
    // Áp dụng lazy cho con trái
    tree[id << 1].sum += val * (mid - l + 1);
    tree[id << 1].lazy += val;
    // Áp dụng lazy cho con phải
    tree[id << 1 | 1].sum += val * (r - mid);
    tree[id << 1 | 1].lazy += val;

    tree[id].lazy = 0;
}

void updateSt(int st, int en, int val, int id = 1, int l = 1, int r = n) {
    if (r < st || en < l) return;
    if (st <= l && r <= en) {
        tree[id].sum += (long long)val * (r - l + 1);
        tree[id].lazy += val;
        return;
    }

    push_down(id, l, r);

    int mid = (l + r) / 2;
    updateSt(st, en, val, id << 1, l, mid);
    updateSt(st, en, val, id << 1 | 1, mid + 1, r);

    tree[id].sum = tree[id << 1].sum + tree[id << 1 | 1].sum;
}

long long getSt(int st, int en, int id = 1, int l = 1, int r = n) {
    if (r < st || en < l) return 0;
    if (st <= l && r <= en) {
        return tree[id].sum;
    }

    push_down(id, l, r);
    
    int mid = (l + r) / 2;
    return getSt(st, en, id << 1, l, mid) + getSt(st, en, id << 1 | 1, mid + 1, r);
}


namespace sub3 {
	
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
    for (int i = 1; i <= n; i++) cin >> a[i];

    sub3::process();

    return 0;
}
int tree[maxn << 2], lazy[maxn << 2];
void Down(int id) {
    if (lazy[id] == (int)1e9) return ;
    minimize(tree[id << 1], lazy[id]);
    minimize(tree[id << 1 | 1], lazy[id]);
    minimize(lazy[id << 1], lazy[id]);
    minimize(lazy[id << 1 | 1], lazy[id]);

    lazy[id] = 1e9;
}

void update(int st, int en, int val, int id = 1, int l = 1, int r = n) {
    if (en < l || r < st) return ;
    if (st <= l && r <= en) {
        minimize(tree[id], val);
        minimize(lazy[id], val);
        return ;
    }
    int mid = l + r >> 1;
    update(st, en, val, id << 1, l, mid);
    update(st, en, val, id << 1 | 1, mid + 1, r);
    tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
}

int get(int st, int en, int id = 1, int l = 1, int r = n) {
    if (en < l || r < st) return ;
    if (st <= l && r <= en) return tree[id];
    int mid = l + r >> 1;
    return min(get(st, en, id << 1, l, mid),
               get(st, en, id << 1 | 1, mid + 1, r));
}
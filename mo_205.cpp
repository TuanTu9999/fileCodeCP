#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
const long long INF = 1e18;

int n, m;

struct block{
    int l, r, v;
};

bool cmp(block a, block b){
    return (a.l < b.l || (a.l == b.l && a.r < b.r));
}

block a[maxn];

long long tree[4 * maxn], lazy[4 * maxn];

void LazyUD(int id){
    if(lazy[id] < INF){
        lazy[id << 1] = min(lazy[id], lazy[id << 1]);
        lazy[id << 1 | 1] = min(lazy[id], lazy[id << 1 | 1]);
        tree[id << 1] = min(lazy[id], tree[id << 1]);
        tree[id << 1 | 1] = min(lazy[id], tree[id << 1 | 1]);
        lazy[id] = INF;
    }
}

void update(int id, int l, int r, int st, int en, long long val){
    if(en < l || r < st) return;
    if(st <= l && r <= en){
        tree[id] = min(tree[id], val);
        lazy[id] = min(lazy[id], val);
        return;
    }
    LazyUD(id);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, st, en, val);
    update(id << 1 | 1, mid + 1, r, st, en, val);
    tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
}

long long query(int id, int l, int r, int st, int en){
    if(en < l || r < st) return INF;
    if(st <= l && r <= en) return tree[id];
    LazyUD(id);
    int mid = (l + r) >> 1;
    return min(query(id << 1, l, mid, st, en),
               query(id << 1 | 1, mid + 1, r, st, en));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> a[i].l >> a[i].r >> a[i].v;
    sort(a + 1, a + m + 1, cmp);
    for(int i = 0; i <= 400000; i++)
        tree[i] = lazy[i] = INF;
    for(int i = 1; i <= m; i++){
        if(a[i].l == 1)
            update(1, 1, n, a[i].l, a[i].r, a[i].v);
        else{
            long long x = query(1, 1, n, a[i].l - 1, a[i].l - 1);
            if(x == INF) return cout << -1, 0;
            long long res = query(1, 1, n, a[i].l - 1, a[i].r);
            update(1, 1, n, a[i].l, a[i].r, res + a[i].v);
        }
    }
    long long Ans = query(1, 1, n, n, n);
    cout << ((Ans != INF) ? Ans : -1);
    return 0;
}

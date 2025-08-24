#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
int n, m;
long long t[4 * maxn];

void ud(int id, int l, int r, int pos, int val){
    if(pos < l || r < pos) return;
    if(l == r){
        t[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    ud(id*2, l, mid, pos, val);
    ud(id*2+1, mid+1, r, pos, val);
    t[id] = max(t[id*2], t[id*2+1]);
}

long long query(int id, int l, int r, int st, int en){
    if(en < l || r < st) return -1e18;
    if(st <= l && r <= en) return t[id];
    int mid = (l + r) / 2;
    return max(query(id*2, l, mid, st, en), query(id*2+1, mid+1, r, st, en));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    while(m--){
        int type, a, b; cin >> type >> a >> b;
        if(type == 0) ud(1, 1, n, a, b);
        else cout << query(1, 1, n, a, b) << '\n';
    }
    return 0;
}

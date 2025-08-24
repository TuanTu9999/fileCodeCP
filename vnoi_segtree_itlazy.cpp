#include <bits/stdc++.h>
#define llong            long long
#define el               cout << '\n'
#define pii              pair<int, int>
#define fi               first
#define se               second
#define veci             vector<int>
#define mapii            map<int, int>
#define pb               push_back

using namespace std;

const int maxn = 4e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, q;
llong t[maxn], lazy[maxn];

void down(int id){
    if(lazy[id]){
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
        t[id*2] += lazy[id];
        t[id*2+1] += lazy[id];
        lazy[id] = 0;
    }
}

void ud(int id, int l, int r, int st, int en, int val){
    if(en < l || r < st) return;
    if(st <= l && r <= en){
        t[id] += val;
        lazy[id] += val;
        return;
    }
    int m = (l + r) / 2;
    down(id);
    ud(id*2, l, m, st, en, val);
    ud(id*2+1, m+1, r, st, en, val);
    t[id] = max(t[id*2], t[id*2+1]);
}

llong getmax(int id, int l, int r, int st, int en){
    if(en < l || r < st) return LLONG_MIN;
    if(st <= l && r <= en) return t[id];
    int m = (l + r) / 2;
    down(id);
    return max(getmax(id*2, l, m, st, en), getmax(id*2+1, m+1, r, st, en));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        int x; cin>>x;
        ud(1, 1, n, i, i, x);
    }
    cin>>q;
    while(q--){
        int k, x, y; cin>>k>>x>>y;
        if(k == 1){
            int val; cin>>val;
            ud(1, 1, n, x, y, val);
        }
        else cout<<getmax(1, 1, n, x, y)<<'\n';
    }
    return 0;
}

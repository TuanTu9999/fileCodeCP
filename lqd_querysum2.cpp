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

const int maxn = 4e6 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, q;
llong t[maxn], f[maxn];

void lazy(int id, int l, int r) {
    if(f[id] == 0) return;
    int m = (l + r) / 2;
    f[id*2] += f[id];
    f[id*2+1] += f[id];
    t[id*2] += 1LL * f[id] * (m - l + 1);
    t[id*2+1] += 1LL * f[id] * (r - m);
    f[id] = 0;
}

void ud(int id, int l, int r, int st, int en, int val) {
    if(en < l || r < st) return;
    if(st <= l && r <= en) {
        t[id] += 1LL * val * (r - l + 1);
        f[id] += val;
        return;
    }
    int m = (l + r) / 2;
    lazy(id, l, r);
    ud(id*2, l, m, st, en, val);
    ud(id*2+1, m+1, r, st, en, val);
    t[id] = t[id*2] + t[id*2+1];
}

llong getsum(int id, int l, int r, int st, int en) {
    if(en < l || st > r) return 0LL;
    if(st <= l && r <= en) return t[id];
    int m = (l + r) / 2;
    lazy(id, l, r);
    llong t1 =  getsum(id*2, l, m, st, en);
    llong t2 =  getsum(id*2+1, m+1, r, st, en);
    return t1 + t2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        int a; cin>>a;
        ud(1, 1, n, i, i, a);
    }
    while(q--){
        int k, l, r; cin>>k>>l>>r;
        if(k == 1){
            int x; cin>>x;
            ud(1, 1, n, l, r, x);
        }
        else cout<<getsum(1, 1, n, l, r)<<'\n';
    }
    return 0;
}

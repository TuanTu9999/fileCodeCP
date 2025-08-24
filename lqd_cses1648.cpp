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

const int maxn = 2e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, q;
llong t[4 * maxn];

llong getf(int id, int l, int r, int st, int en){
    if(r < st || en < l) return 0;
    if(l <= st && en <= r) return t[id];
    int m = (st + en) / 2;
    return getf(id*2, l, r, st, m) + getf(id*2+1, l, r, m + 1, en);
}

void ud(int id, int pos, int val, int st, int en){
    if(pos < st || pos > en) return;
    if(st == en){
        t[id] = val;
        return;
    }
    int m = (st + en) / 2;
    ud(id*2, pos, val, st, m);
    ud(id*2+1, pos, val, m + 1, en);
    t[id] = t[id*2] + t[id*2+1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        int x; cin>>x;
        ud(1, i, x, 1, n);
    }
    while(q--){
        int k, a, b;
        cin>>k>>a>>b;
        if(k == 1) ud(1, a, b, 1, n);
        else cout<<getf(1, a, b, 1, n)<<'\n';
    }
    return 0;
}

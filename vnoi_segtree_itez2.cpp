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
llong t[maxn];

void ud(int id, int l, int r, int pos, int val){
    if(pos < l || r < pos) return;
    if(l == r){
        t[id] = val;
        return;
    }
    int m = (l + r) / 2;
    ud(id*2, l, m, pos, val);
    ud(id*2+1, m+1, r, pos, val);
    t[id] = t[id*2] + t[id*2+1];
}

llong getsum(int id, int l, int r, int st, int en){
    if(en < l || r < st) return 0LL;
    if(st <= l && r <= en) return t[id];
    int m = (l + r) / 2;
    return getsum(id*2, l, m, st, en) + getsum(id*2+1, m+1, r, st, en);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>q;
    while(q--){
        int k, a, b;
        cin>>k>>a>>b;
        if(k == 1){
            ud(1, 1, n, a, b);
        }
        else{
            cout<<getsum(1, 1, n, a, b)<<'\n';
        }
    }
    return 0;
}

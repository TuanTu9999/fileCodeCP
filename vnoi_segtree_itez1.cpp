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

const int maxn = 1e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, q, t[4 * maxn];

void ud(int pos, int val, int id, int l, int r) {
    if (l == r) {
        t[id] = val;
    } else {
        int m = (l + r) / 2;
        if (pos <= m) ud(pos, val, id * 2, l, m);
        else ud(pos, val, id * 2 + 1, m + 1, r);
        t[id] = max(t[id * 2], t[id * 2 + 1]);
    }
}

int getf(int u, int v, int id, int l, int r) {
    if (v < l || u > r) return -ooi;
    if (u <= l && r <= v) return t[id];
    int m = (l + r) / 2;
    int maxL = getf(u, v, id * 2, l, m);
    int maxR = getf(u, v, id * 2 + 1, m + 1, r);
    return max(maxL, maxR);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        int x; cin>>x;
        ud(i, x, 1, 1, n);
    }
    cin>>q;
    while(q--){
        int k, l, r;
        cin>>k>>l>>r;
        if(k == 1) ud(l, r, 1, 1, n);
        else cout<<getf(l, r, 1, 1, n)<<'\n';
    }
    return 0;
}

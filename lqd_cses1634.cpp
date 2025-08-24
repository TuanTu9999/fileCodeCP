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

const int maxn = 1e2 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>k;
    veci a(n);
    for(int& x : a) cin>>x;
    veci f(k + 1, ooi);
    f[0] = 0;
    for(int s = 1; s <= k; s++)
        for(int x : a)
            if(s >= x) f[s] = min(f[s], f[s - x] + 1);
    if(f[k] == ooi) cout<<"-1";
    else cout<<f[k];
    return 0;
}

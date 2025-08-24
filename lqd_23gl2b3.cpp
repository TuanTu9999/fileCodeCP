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
#define FILENAME "CLIMBSTAIR"

int n, m, a[maxn], pre[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(FILENAME".INP", "r", stdin);
    freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];
    pre[0] = 0;
    for(int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], a[i - 1]);
    for(int i = 1; i <= n; i++) cout<<pre[i]<<' ';
    el;
    while(m--){
        int t; cin>>t;
        cout<<upper_bound(pre + 1, pre + n + 1, t) - pre - 1<<'\n';
    }
    return 0;
}

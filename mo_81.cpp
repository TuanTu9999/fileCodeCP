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

int n, q;
pii a[maxn];
llong pre[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>q;
    for(int i = 0; i < n; i++){
        cin>>a[i].second>>a[i].first;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        pre[i + 1] = pre[i] + a[i].second;
    }
    while(q--){
        llong k; cin>>k;
        int id = lower_bound(pre + 1, pre + n + 1, k) - pre;
        cout<<a[id - 1].first<<'\n';
    }
    return 0;
}

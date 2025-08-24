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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>q;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        a[i] = make_pair(x, i);
    }
    sort(a, a + n);
    while(q--){
        int l, r, k; cin>>l>>r>>k;
        cout<<upper_bound(a, a + n, make_pair(k, r - 1)) - lower_bound(a, a + n, make_pair(k, l - 1))<<'\n';
    }
    return 0;
}

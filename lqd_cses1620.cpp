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

const int maxn = 1e6 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

llong l, r, m, ans;
int n, t, a[maxn];

bool check(llong k){
    llong tmp = 0;
    for(int i = 0; i < n; i++){
        tmp += k / a[i];
        if(tmp >= t) return true;
    }
    return (tmp >= t);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>t;
    for(int i = 0; i < n; i++) cin>>a[i];
    l = 1;
    r = 1LL * (*max_element(a, a + n)) * t;
    ans = r;
    while(l <= r){
        m = (l + r) / 2;
        if(check(m)){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout<<ans;
    return 0;
}

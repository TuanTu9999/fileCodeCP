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
const int MOD = 1e9;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME "MUL"

int n, a[maxn];
llong ans;

int binPow(int a, int b){
    if(b == 0) return 1;
    a %= MOD;
    int tmp = binPow(a, b >> 1);
    tmp = (1LL * tmp * tmp) % MOD;
    if(b & 1) return (1LL * a * tmp) % MOD;
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(FILENAME".INP", "r", stdin);
    freopen(FILENAME".OUT", "w", stdout);
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++){
        int b; cin>>b;
        ans += binPow(a[i], b);
    }
    cout<<ans % MOD;
    return 0;
}

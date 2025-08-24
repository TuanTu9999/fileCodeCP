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

int binPow(int a, int b, int m){
    int res = 1;
    while(b > 0){
        if(b & 1) res = (1LL * res * a) % m;
        b >>= 1;
        a = (1LL * a * a) % m;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    int t; cin>>t;
    while(t--){
        int a, b, c; cin>>a>>b>>c;
        cout<<binPow(a, binPow(b, c, MOD - 1), MOD)<<'\n';
    }
    return 0;
}

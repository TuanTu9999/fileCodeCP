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

llong binPow(llong x, int y){
    llong res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    int t; cin>>t;
    while(t--){
        llong n; cin>>n;
        int i = 1;
        llong p = 9LL;
        while(true){
            if(p >= n) break;
            n -= p;
            i++;
            p = 9LL * binPow(10, i - 1) * i;
        }
        n--;
        int id = n % i;
        string digit = to_string(binPow(10, i - 1) + n / i);
        cout<<digit[id]<<'\n';
    }
    return 0;
}

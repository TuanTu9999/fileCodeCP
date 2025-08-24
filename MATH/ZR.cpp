#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
const int MOD = 1e9 + 7;
long long ans;
int n;

int binPow(long long a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    ans = 1;
    for(int i = 2; i <= n; i++){
        ans = ((ans * i) % MOD) * binPow(__gcd(ans, 1LL * i), MOD - 2);
        ans %= MOD;
    }
    cout << ans % MOD;
    return 0;
}

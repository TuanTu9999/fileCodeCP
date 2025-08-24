#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
const long long MOD = 1e9 + 7;

long long n;

int binPow(long long a, int b){
    long long res = 1;
    a %= MOD;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int binMul(long long a, long long b){
    long long res = 0;
    a %= MOD;
    while(b){
        if(b & 1) res = res + a % MOD;
        a = a * 2LL % MOD;
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
    n %= MOD;
    cout << ((((n * (n + 1) % MOD) * (2LL * n + 1)) % MOD) * binPow(6, MOD - 2)) % MOD;
    return 0;
}

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

const int maxn = 1e7 + 3;
const int MOD = 998244353;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int minpf[maxn];

void sieve(int n){
    minpf[0] = minpf[1] = 1;
    for(int i = 2; i * i <= n; i++){
        if(minpf[i] == 0){
            for(int j = i; j <= n; j += i){
                if(minpf[j] == 0) minpf[j] = i;
            }
        }
    }
}

int binPow(int a, int b){
    a %= MOD;
    int res = 1;
    while(b > 0){
        if(b & 1) res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

bool scp(int n){
    int t = sqrt(n);
    return (t * t == n);
}

llong cntdivi(int n){
    llong res = 1;
    while(n > 1){
        int t = minpf[n], cnt = 0;
        if(t == 0) t = n;
        while(n % t == 0){
            n /= t;
            cnt++;
        }
        res *= (cnt + 1);
    }
    return res;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    sieve(1e7);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int tmp = binPow(n, cntdivi(n) / 2);
        if(scp(n)) cout<<(1LL * tmp * (llong)sqrt(n)) % MOD<<'\n';
        else cout<<tmp<<'\n';
    }
}
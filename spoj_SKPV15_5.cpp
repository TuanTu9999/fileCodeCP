#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
const int MOD = 1e9 + 9;

int n, m, k;
int minpf[maxn], c[3][maxn];
long long Ans = 1, _pow[maxn];

// n: GCD (0)
// m: LCM (1)

void sieve(int ln){
    for(int i = 1; i <= ln; i++) minpf[i] = i;
    for(int i = 2; i * i <= ln; i++){
        if(minpf[i] == i)
            for(int j = i * i; j <= ln; j += i) minpf[j] = i;
    }
}

long long binPow(long long a, int b){
    long long res = 1;
    while(b){
        if(b & 1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return res;
}

void facDiv(int a, int f){
    while(a > 1){
        int t = minpf[a];
        c[f][t]++;
        a /= t;
    }
}

long long IEP(int mi, int ma){ // bao hàm loại trừ
    if(ma == mi) return 1LL;
    long long A = binPow(ma - mi + 1, k); // số lượng dãy tồn tại cả ma và mi
    long long B = binPow(ma - mi, k);     // số lượng dãy chỉ có ma hoặc mi
    long long C = binPow(ma - mi - 1, k); // số lượng dãy không có ma và mi
    return ((A - 2LL * B + C) % MOD + MOD) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    sieve(1e6);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        facDiv(x, 0);
    }
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        facDiv(x, 1);
    }
    for(int i = 2; i <= 1000000; i++){
        if(minpf[i] == i){
            if(c[0][i] > c[1][i]) return cout << 0, 0;
            Ans = (Ans * IEP(c[0][i], c[1][i])) % MOD;
        }
    }
    cout << Ans;
    return 0;
}

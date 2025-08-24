#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
int n, k, minpf[maxn], c[maxn];

void sieve(){
    int n = 1e6;
    for(int i = 2; i * i <= n; i++){
        if(!minpf[i]){
            for(int j = i; j <= n; j += i){
                if(!minpf[j]) minpf[j] = i;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    sieve();
    cin >> n >> k;
    for(int i = 2; i <= k; i++) c[minpf[i]]++;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        cout << max(c[x], 1) << '\n';
    }
    return 0;
}

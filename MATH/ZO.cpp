#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 3;
int n, k, ans, f[maxn];

void sieve(){
    int n = 2e6;
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n; j += i) f[j]++;
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
    for(int i = 1; i <= n; i++){
        if(f[i] == k - 1) ans++;
    }
    cout << ans;
    return 0;
}

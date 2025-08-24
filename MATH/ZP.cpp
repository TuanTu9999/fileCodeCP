#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 5;
int n, f[maxn], ans;

void sieve(){
    int limit = 2e6;
    for(int i = 2; i <= limit; i++)
        for(int j = i; j <= limit; j += i)
            f[j]++;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    sieve();
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ans = max(ans, f[x]);
    }
    cout << ans + 1;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 3;
int n, f[maxn], c[3][3 * maxn], ans, b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> b;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        f[i] = f[i - 1] + (x > b) - (x < b);
    }
    for(int i = 1; i <= n; i++){
        c[i % 2][f[i - 1] + maxn]++;
        ans += c[i % 2][f[i] + maxn];
    }
    cout << ans;
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
int n, m, k, b[maxn], c[maxn], ln;
long long ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ln = max(ln, x);
        c[x]++;
    }
    for(int i = 1; i <= m; i++) cin >> b[i];
    for(int i = 1; i <= m; i++){
        for(int j = k * b[i]; j <= ln; j += k * b[i]){
            ans += c[j];
        }
    }
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> t;
    while(t--){
        cin >> n >> k;
        int ans = 0;
        for(int i = k; i <= n; i *= k) ans += n / i;
        cout << ans << '\n';
    }
    return 0;
}

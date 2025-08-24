#include <bits/stdc++.h>

using namespace std;

int n, x, y;
long long ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> ans;
    for(int i = 1; i < n; i++){
        int x; cin >> x;
        ans = ans / __gcd(ans, 1LL * x) * x;
    }
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;
long long ans, x;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> x >> ans;
    for(int i = 1; i < n; i++){
        int num; cin >> num;
        ans = ans / __gcd(ans, 1LL * num) * num;
    }
    cout << ans * (long long)ceil(1.0 * x / ans);
    return 0;
}

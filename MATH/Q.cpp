#include <bits/stdc++.h>

using namespace std;

const int maxn = 1003;
int n, k, a[maxn], ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n - k + 1; i++){
        int res = a[i];
        for(int j = i + 1; j <= i + k - 1; j++) res = __gcd(res, a[j]);
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}

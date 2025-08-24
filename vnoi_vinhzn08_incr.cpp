#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
int n, d;
long long a[maxn], ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++){
        if(a[i] <= a[i - 1]){
            int t = (a[i - 1] - a[i] + 1) / d + ((a[i - 1] - a[i] + 1) % d != 0);
            t = max(t, 1);
            a[i] += 1LL * t * d;
            ans += t;
        }
    }
    cout << ans;
    return 0;
}

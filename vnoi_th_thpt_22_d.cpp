#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
int t, n, k, a[maxn], ma;
long long sum;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME "EQLARRAY"
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> t;
    while(t--){
        cin >> n >> k;
        sum = 0;
        ma = -1e9;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            ma = max(ma, a[i]);
            sum += a[i];
        }
        if(sum % k == 0 && 1LL * k * ma <= sum) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

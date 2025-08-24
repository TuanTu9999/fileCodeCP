#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
int n, k;
long long sum[maxn], pre[maxn], ans = -1e18;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    for(int i = 1; i <= n; i++) pre[i] = min(pre[i - 1], sum[i]);
    for(int i = k; i <= n; i++)
        ans = max(ans, sum[i] - pre[i - k]);
    cout << ans;
    return 0;
}

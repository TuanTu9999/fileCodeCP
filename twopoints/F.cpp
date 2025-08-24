#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 3;

int n, k, a[maxn];
long long pre[maxn], Ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    for(int i = 1; i <= k; i++) Ans = max({Ans, pre[n] - pre[2 * (k - i)] - pre[n] + pre[n - i],
                                                pre[n] - pre[2 * i] - pre[n] + pre[n - k + i]});
    cout << Ans;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
int n, a[maxn], pre[maxn], suf[maxn], ans = 1e9;
/*
    pre[i]: dem so 2 truoc i
    suf[i]: dem so 2 sau i
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (a[i] == 2);
    for(int i = n; i > 0; i--) suf[i] = suf[i + 1] + (a[i] == 1);
    for(int i = 1; i <= n; i++) ans = min(ans, pre[i - 1] + suf[i + 1]);
    cout << ans;
    return 0;
}

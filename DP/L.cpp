#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
int n, a[maxn], L[maxn], R[maxn], ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        if(a[i]) L[i] = L[i - 1] + 1;
        else L[i] = 0;
    }
    for(int i = n; i > 0; i--){
        if(a[i]) R[i] = R[i + 1] + 1;
        else R[i] = 0;
    }
    for(int i = 2; i < n; i++) ans = max(ans, L[i - 1] + R[i + 1]);
    cout << ans;
    return 0;
}

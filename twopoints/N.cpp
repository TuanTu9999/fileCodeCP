#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, k, a[maxn], Ans, c[maxn];

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
    for(int i = 1; i <= k; i++){
        Ans += c[a[i]];
        c[a[i]]++;
    }
    for(int i = k + 1; i <= n; i++){
        c[a[i - k - 1]]--;
        Ans += c[a[i]];
        c[a[i]]++;
    }
    cout << Ans;
    return 0;
}

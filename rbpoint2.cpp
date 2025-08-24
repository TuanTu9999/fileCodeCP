#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, b[maxn], r[maxn], Ans = 2e9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")){
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i) cin >> r[i];
    sort(b + 1, b + n + 1);
    sort(r + 1, r + n + 1);
    for(int i = 1; i <= n; ++i){
        int pos = lower_bound(r + 1, r + n + 1, b[i]) - r;
        if(pos <= n) Ans = min(Ans, r[pos] - b[i]);
        pos = upper_bound(r + 1, r + n + 1, b[i]) - r - 1;
        if(pos > 0) Ans = min(Ans, b[i] - r[pos]);
    }
    cout << Ans;
    return 0;
}
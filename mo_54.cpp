#include <bits/stdc++.h>

using namespace std;

int n, s, w[21], v[21];

long long backtrack(int k, int W, long long val){
    if(k == n + 1){
        if(W >= 0) return val;
        else return -1;
    }
    return max(backtrack(k + 1, W - w[k], val + v[k]),
               backtrack(k + 1, W, val));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    cout << backtrack(1, s, 0);
    return 0;
}

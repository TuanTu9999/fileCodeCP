#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, k, pre[maxn], Ans = maxn;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        char x; cin >> x;
        pre[i] = pre[i - 1];
        if(x == 'W') pre[i]++;
    }
    for(int i = k; i <= n; i++){
        Ans = min(Ans, pre[i] - pre[i - k]);
    }
    cout << Ans;
    return 0;
}

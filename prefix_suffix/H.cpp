#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, pre[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        int id = lower_bound(pre + 1, pre + n + 1, k) - pre;
        if(id <= n) cout << id;
        else cout << -1;
        cout << ' ';
    }
    return 0;
}

#include <bits/stdc++.h>
#define llong long long

using namespace std;

const int maxn = 1e6 + 3;
int n, q;
llong pre[maxn];

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
    cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }
    return 0;
}

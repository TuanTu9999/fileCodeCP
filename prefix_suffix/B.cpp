#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, a[maxn], q, x;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    sort(a, a + n);
    while(q--){
        cin >> x;
        int id = upper_bound(a, a + n, x) - a - 1;
        if(0 <= id && id < n && a[id] <= x) cout << a[id] << '\n';
        else cout << "-1\n";
    }
    return 0;
}

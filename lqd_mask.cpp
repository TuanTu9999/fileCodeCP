#include <bits/stdc++.h>

using namespace std;

int n, q, a[(int)1e5 + 3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    cin >> q;
    while(q--){
        int m; cin >> m;
        int id = lower_bound(a + 1, a + n + 1, m) - a - 1;
        cout << id << '\n';
    }
    return 0;
}

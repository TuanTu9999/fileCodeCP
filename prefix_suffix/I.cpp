#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n;
pair<int, int> a[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        int l = lower_bound(a + 1, a + n + 1, make_pair(x, 1)) - a;
        int r = upper_bound(a + 1, a + n + 1, make_pair(x, n)) - a - 1;
        if(a[l].first == x) cout << l << ' ' << r << '\n';
        else cout << "-1 -1\n";
    }
    return 0;
}

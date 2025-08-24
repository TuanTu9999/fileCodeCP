#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, x;
long long ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        int pos; cin >> pos;
        ans += abs(pos - x);
    }
    cout << ans;
    return 0;
}

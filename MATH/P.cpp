#include <bits/stdc++.h>

using namespace std;

int t, n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << (1LL * n * (n + 1) * (2LL * n + 1) / 6) << '\n';
    }
    return 0;
}

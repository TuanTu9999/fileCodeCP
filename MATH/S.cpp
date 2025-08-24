#include <bits/stdc++.h>

using namespace std;

int n, ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 2; i <= n; i *= 2){
        ans += n / i;
    }
    cout << ans;
    return 0;
}

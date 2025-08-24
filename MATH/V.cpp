#include <bits/stdc++.h>

using namespace std;

long long l, r, k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> k >> l >> r;
    cout << r / k - (l - 1) / k;
    return 0;
}

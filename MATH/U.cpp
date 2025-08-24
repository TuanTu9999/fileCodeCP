#include <bits/stdc++.h>
#define llong long long

using namespace std;

llong l, r;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> l >> r;
    cout << (llong)floor(sqrt(r)) - (llong)ceil(sqrt(l)) + 1;
    return 0;
}

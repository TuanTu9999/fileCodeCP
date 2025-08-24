#include <bits/stdc++.h>

using namespace std;

long long n, p;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> p;
    long long tmp = min(n - p, p) - 1;
    cout << (long long)ceil(1.0 * tmp / 2);
    return 0;
}

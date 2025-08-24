#include <bits/stdc++.h>

using namespace std;

long long a, b, c, d;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> a >> b >> c >> d;
    long long lcm = c / __gcd(c, d) * d;
    a--;
    cout << b/c - a/c + b/d - a/d - b/lcm + a/lcm;
    return 0;
}

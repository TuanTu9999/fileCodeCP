#include <bits/stdc++.h>

using namespace std;

long long n, m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    long long gcd = __gcd(n, m);
    cout << gcd << '\n';
    cout << n / gcd << ' ' << m / gcd;
    return 0;
}

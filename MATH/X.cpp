#include <bits/stdc++.h>

using namespace std;

long long x, y, n, m, lc;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x >> y;
    lc = x / __gcd(x, y) * y;
    cout << m/ lc - (n - 1) / lc;
    return 0;
}

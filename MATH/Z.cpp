#include <bits/stdc++.h>

using namespace std;

int m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m;
    int a = m / 3;
    int b = m / 15;
    cout << 3LL * a * (a + 1) / 2 - 15LL * b * (b + 1) / 2;
    return 0;
}

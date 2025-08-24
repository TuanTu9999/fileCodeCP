#include <bits/stdc++.h>

using namespace std;

int n;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = n / 2; i > 0; i--){
        int j = n - i;
        if(__gcd(i, j) == 1){
            cout << 1LL * i * j;
            return 0;
        }
    }
}

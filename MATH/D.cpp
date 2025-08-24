#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, ans;

bool isPrime(int a){
    if(a == 2 || a == 3) return 1;
    if(a < 2 || a % 2 == 0 || a % 3 == 0) return 0;
    for(int i = 5; i * i <= a; i += 6)
        if(a % i == 0 || a % (i + 2) == 0) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ans += isPrime(x);
    }
    cout << ans;
    return 0;
}

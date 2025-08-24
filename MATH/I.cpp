#include <bits/stdc++.h>

using namespace std;

long long n, res = 1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(long long i = 2; i * i <= n; i++){
        int cnt = 0;
        while(n % i == 0){
            cnt++;
            n /= i;
        }
        res *= (cnt + 1);
    }
    if(n > 1) res *= 2;
    cout << res;
    return 0;
}

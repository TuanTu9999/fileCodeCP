#include <bits/stdc++.h>

using namespace std;

int n, cnt;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            cnt++;
        }
    }
    if(n > 1) cnt++;
    cout << cnt;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long n;
int ans;

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
        ans = max(ans, cnt);
    }
    if(n > 1) ans = max(ans, 1);
    cout << ans;
    return 0;
}

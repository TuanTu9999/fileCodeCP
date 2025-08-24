#include <bits/stdc++.h>

using namespace std;

int n, ans;

int cntDiv(int a){
    int res = 1;
    for(int i = 2; i * i <= a; i++){
        int cnt = 0;
        while(a % i == 0){
            cnt++;
            a /= i;
        }
        res *= (cnt + 1);
    }
    if(a > 1) res *= 2;
    return res;
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
        ans = max(ans, cntDiv(x));
    }
    cout << ans;
    return 0;
}

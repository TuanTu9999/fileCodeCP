#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e6 + 3;

int n, ans;
bool kt[maxn + 2];

void sieve(int n){
    kt[0] = kt[1] = 1;
    for(int i = 2; i * i <= n; i++){
        if(!kt[i]){
            for(int j = i * i; j <= n; j += i) kt[j] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    sieve(maxn);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ans += (!kt[x]);
    }
    cout << ans;
    return 0;
}

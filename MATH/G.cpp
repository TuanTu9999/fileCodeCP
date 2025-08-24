#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e7 + 3;

int l, r, ans;
bool kt[maxn + 2];

int sumDigit(int a){
    kt[0] = kt[1] = 1;
    int res = 0;
    while(a){
        res += a % 10;
        a /= 10;
    }
    return res;
}

void sieve(int n){
    for(int i = 2; i * i <= n; i++){
        if(!kt[i]){
            for(int j = i * i; j <= n; j += i) kt[j] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> l >> r;
    sieve(r + 2);
    for(int i = l; i <= r; i++){
        if(!kt[i] && !kt[sumDigit(i)]) cout << i << ' ';
    }
    return 0;
}

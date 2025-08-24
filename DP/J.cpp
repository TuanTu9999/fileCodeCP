#include <bits/stdc++.h>

using namespace std;

const int maxn = 5003;
int n, a[maxn], f[maxn];
bool kt[(int)2e6 + 3];

void sieve(){
    int lim = 2e6;
    kt[0] = kt[1] = 1;
    for(int i = 2; i * i <= lim; i++){
        if(!kt[i]){
            for(int j = i * i; j <= lim; j += i) kt[j] = 1;
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
    sieve();
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        f[i] = 1;
        for(int j = 1; j < i; j++){
            if(!kt[a[i] + a[j]]) f[i] = max(f[i], f[j] + 1);
        }
    }
    cout << *max_element(f + 1, f + n + 1);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
const int MOD = 1e9 + 7;

int n, c[maxn];
long long Ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    c[0] = 1;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        (Ans += c[x]) %= MOD;
        c[x]++;
    }
    cout << Ans;
    return 0;
}

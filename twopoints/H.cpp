#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 3;

int n, s, a[maxn], Ans = maxn;
long long sum;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) a[i + n] = a[i];
    n *= 2;
    int l = 1;
    for(int r = 1; r <= n; r++){
        sum += a[r];
        while(sum >= s && l <= n){
            Ans = min(Ans, r - l + 1);
            sum -= a[l];
            l++;
        }
    }
    if(Ans <= n / 2) cout << Ans;
    else cout << -1;
    return 0;
}

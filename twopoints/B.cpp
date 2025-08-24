#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, x, a[maxn];
long long sum, Ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1;
    for(int r = 1; r <= n; r++){
        sum += a[r];
        while(sum >= x && l <= n){
            if(sum == x) Ans++;
            sum -= a[l];
            l++;
        }
    }
    cout << Ans;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, m, a[maxn], h[maxn], pre[maxn], Ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> h[i];
    int l = 1;
    long long sum = a[1];
    for(int r = 2; r <= n; r++){
        if(h[r - 1] % h[r] == 0) sum += a[r];
        else{
            l = r;
            sum = a[r];
        }
        while(sum > m && l <= n){
            sum -= a[l];
            l++;
        }
        Ans = max(Ans, r - l + 1);
    }
    cout << Ans;
    return 0;

}

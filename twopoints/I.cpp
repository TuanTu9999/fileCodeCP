#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, k, a[maxn], c[maxn];
long long Ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, d = 0;
    for(int r = 1; r <= n; r++){
        if(!c[a[r]]) d++;
        c[a[r]]++;
        while(d > k && l <= n){
            c[a[l]]--;
            if(!c[a[l]]) d--;
            l++;
        }
        Ans += r - l + 1;
    }
    cout << Ans;
    return 0;
}

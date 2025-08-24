#include <bits/stdc++.h>

using namespace std;

const int maxn = 8010;

int n, a[maxn];
long long Ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")){
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int k = 2; k <= n; ++k){
        int l = 1, r = k - 1;
        while(l < r){
            if(a[l] + a[r] > a[k]){
                Ans += r - l;
                --r;
            }
            else ++l;
        }
    }
    cout << Ans;
    return 0;
}
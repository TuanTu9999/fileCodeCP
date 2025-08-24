#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int n, d, a[maxn];
long long Ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1;
    for(int r = 1; r <= n; r++){
        while(a[r] - a[l] > d && l <= n) l++;
        int x = r - l;
        Ans += 1LL * x * (x - 1) / 2;
    }
    cout << Ans;
    return 0;
}

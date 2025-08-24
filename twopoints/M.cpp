#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 3;

int n, a[maxn], Ans;
map<int, int> c;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1;
    for(int r = 1; r <= n; r++){
        c[a[r]]++;
        auto it = c.find(a[r]);
        while((*it).second > 1 && l <= n){
            c[a[l]]--;
            l++;
        }
        Ans = max(Ans, r - l + 1);
    }
    cout << Ans;
    return 0;
}

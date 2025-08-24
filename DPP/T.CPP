#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int n, a[maxn], Ans;

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
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 4){
            Ans++;
            continue;
        }
        if(sum + a[i] >= 4){
            sum = 0;
            sum = a[i];
            Ans++;
        }
        sum += a[i];
    }
    if(sum) Ans++;
    cout << Ans;
    return 0;
}

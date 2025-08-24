#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
int n, a[maxn];
long long ans, sum;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        sum += a[i];
        ans = max(ans, sum);
        if(sum < 0){
            sum = 0;
            ans = max(ans, sum);
        }
    }
    cout << max(ans, sum);
    return 0;
}

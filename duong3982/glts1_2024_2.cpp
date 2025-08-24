#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, k, b, a[maxn];
long long sum, Ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME "BAI2"
    if(fopen(FILENAME".INP", "r")){
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n >> k >> b;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    Ans += sum * (k / n);
    k %= n;
    int i = (b % n == 0) ? 1 : b % n;
    while(k--){
        Ans += a[i];
        i = (i == n) ? 1 : i + 1;
    }
    cout << Ans;
    return 0;
}
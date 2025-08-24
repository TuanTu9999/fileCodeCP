#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, m, Ans;
long long a[maxn], b[maxn];

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
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> b[i];

    for(int i = 1; i <= n; i++) a[i] += a[i - 1];
    for(int i = 1; i <= m; i++) b[i] += b[i - 1];

    int i = 1, j = 1;
    while(i <= n && j <= m){
        if(a[i] == b[j]){
            i++;
            j++;
            Ans++;
        }
        else if(a[i] < b[j]) i++;
        else j++;
    }
    cout << Ans;
    return 0;
}

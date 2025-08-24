#include <bits/stdc++.h>

using namespace std;

const int maxn = 21;
int n, k, a[maxn];

void backtrack(int i){
    if(i == k + 1){
        for(int j = 1; j <= k; j++) cout << a[j] << ' ';
        cout << '\n';
        return;
    }
    if(i > n) return;

    for(int j = a[i - 1] + 1; j <= n; j++){
        a[i] = j;
        backtrack(i + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    backtrack(1);
    return 0;
}

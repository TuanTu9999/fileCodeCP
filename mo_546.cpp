#include <bits/stdc++.h>

using namespace std;

int n, k, a[8];
bool used[8];

void backtrack(int i){
    if(i == k + 1){
        for(int j = 1; j <= k; j++) cout << a[j] << ' ';
        cout << '\n';
    }
    if(i > n) return;

    for(int j = 1; j <= n; j++){
        if(!used[j]){
            a[i] = j;
            used[j] = 1;
            backtrack(i + 1);
            used[j] = 0;
        }
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

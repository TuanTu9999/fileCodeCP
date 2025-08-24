#include <bits/stdc++.h>

using namespace std;

const int maxn = 11;
int n, k, a[maxn], sum[maxn], group[maxn];
bool br;

void backtrack(int i){
    if(br) return;
    if(i == n + 1){
        for(int p = 2; p <= k; p++){
            if(sum[p] != sum[p - 1] || sum[p] == 0) return;
        }
        for(int p = 1; p <= n; p++) cout << group[p] << ' ';
        br = 1;
        return;
    }

    for(int p = 1; p <= k; p++){
        sum[p] += a[i];
        group[i] = p;
        backtrack(i + 1);
        sum[p] -= a[i];
        group[i] = 0;
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
    for(int i = 1; i <= n; i++) cin >> a[i];
    backtrack(1);
//    for(int i = 1; i <= n; i++) cout << group[i] << ' ';
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int a[5][5];

long long backtrack(int i, int j, long long res){
    if(i < 0 || j < 0 || i > 4 || j > 4) return 0LL;
    if(i == 4 && j == 4) return res;
    return max(backtrack(i + 1, j, res + a[i + 1][j]),
               backtrack(i, j + 1, res + a[i][j + 1]));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            cin >> a[i][j];
    cout << backtrack(1, 1, 0) + a[1][1];
    return 0;
}

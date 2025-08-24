#include <bits/stdc++.h>

using namespace std;

long long n, m;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> m >> n;
    n %= 60;
    n += m;
    n %= 60;
    cout << n;
    return 0;
}

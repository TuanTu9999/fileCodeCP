#include <bits/stdc++.h>

using namespace std;

int n, a;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    while(n--){
        cin >> a;
        for(int i = sqrt(a); i > 0; i--){
            if(a % (i * i) == 0){
                cout << i << ' ' << a / (i * i) << '\n';
                break;
            }
        }
    }
    return 0;
}

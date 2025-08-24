#include <bits/stdc++.h>

using namespace std;

string s;
long long sum;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> s;
    for(char x : s) sum += (int)x - 48;
    cout << sum;
    return 0;
}

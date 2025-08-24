#include <bits/stdc++.h>

using namespace std;

string a, b;

long long format(string& s){
    long long res = 0 , mu = 1;
    for(int i = s.size() - 1; i >= 0; i--, mu <<= 1)
        res += (s[i] - '0') * mu;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> a >> b;
    cout << (int)sqrt(format(b)) - (int)sqrt(format(a) - 1);
    return 0;
}

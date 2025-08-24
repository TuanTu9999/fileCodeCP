#include <bits/stdc++.h>

using namespace std;

string n;
int l, r, ans;

string tostring(int a){
    string s;
    int n = (int)log10(a) + 1;
    s.resize(n);
    while(a){
        n--;
        s[n] = (a % 10 + '0');
        a /= 10;
    }
    return s;
}

bool check(int a){
    string s = tostring(a);
    if(s.find(n) <= s.size()) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> l >> r;
    for(int i = l; i <= r; i++) ans += check(i);
    cout << ans;
    return 0;
}

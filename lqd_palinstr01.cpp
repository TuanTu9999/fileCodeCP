#include <bits/stdc++.h>

using namespace std;

string s;

bool solve(){
    int l = 0, r = s.size() - 1, res = 0;
    while(l < r){
        if(s[l] != s[r]) res++;
        l++;
        r--;
    }
    return (res <= 2);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME "nguyenttuca"
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    while(cin >> s){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

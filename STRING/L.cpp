#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

const string Ans = "Happy New Year!!!";
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    int T; cin >> T;
    cin.ignore();
    while(T--){
        getline(cin, s);
        if(s == Ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
string s, t;
int match[maxn], kmp[maxn], n, m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> s >> t;
    n = s.size(); s = ' ' + s;
    m = t.size(); t = ' ' + t;
    int k = kmp[1] = 0;
    for(int i = 2; i <= m; i++){
        while(k > 0 && t[i] != t[k + 1]) k = kmp[k];
        kmp[i] = t[i] == t[k + 1] ? ++k : 0;
    }
    k = 0;
    for(int i = 1; i <= n; i++){
        while(k > 0 && s[i] != t[k + 1]) k = kmp[k];
        match[i] = s[i] == t[k + 1] ? ++k : 0;
        if(match[i] == m) cout << i - m + 1 << ' ';
    }
    return 0;
}

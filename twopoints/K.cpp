#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

string s, t;
int c[260], c1[260], n, m, Ans;
vector<char> a;

bool check(){
    for(char x : a){
        if(c[(int)x] != c1[(int)x]) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> s >> t;
    n = s.size();
    s = ' ' + s;
    m = t.size();
    t = ' ' + t;
    for(int i = 1; i <= m; i++){
        if(!c1[(int)t[i]]) a.push_back(t[i]);
        c1[(int)t[i]]++;
    }
    for(int i = 1; i <= m; i++) c[(int)s[i]]++;
    for(int i = m + 1; i <= n; i++){
        if(check()) Ans++;
        c[s[i]]++;
        c[s[i - m]]--;
    }
    if(check()) Ans++;
    cout << Ans;
    return 0;
}

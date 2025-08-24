#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

string s;
int n, Ans, c[260];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> s;
    n = s.size(); s = ' ' + s;
    int l = 1, r = n;
    while(l < r){
        if(s[l] == s[r]){
            l++;
            r--;
        }
        else if(s[l] == 'm'){
            l++;
            Ans++;
        }
        else if(s[r] == 'm'){
            r--;
            Ans++;
        }
        else return cout << -1, 0;
    }
    cout << Ans;
    return 0;
}

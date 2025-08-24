#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;
const int MOD = 1e9 + 7;

string s;
int n;
long long Ans = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")){
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> s;
    n = s.size(); s = ' ' + s + ' ';
    long long d = 1;
    for(int i = 1; i <= n + 1; i++) {
        if(s[i] == s[i - 1]) d++;
        else {
            Ans *= d;
            Ans %= MOD;
            d = 1;
        }
    }
    cout << Ans;
    return 0;
}
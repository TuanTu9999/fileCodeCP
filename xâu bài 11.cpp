#include <bits/stdc++.h>

using namespace std;

int n;
string s;

string memo[1000010];
int sz;

bool check(int len) {
    set<string> se;
    for (int l = 0; l + len - 1 <= n - 1; l++) {
        
        string t = s.substr(l, len);
        for (int i = 1; i <= sz; i++) {
            if (memo[i] == t) {
                for (int i = 1; i <= sz; i++) {
                    memo[i] = "";
                }
                sz = 0;
                return false;
            }
        }
        sz++;
        memo[sz] = t;
        
    }
    
    for (int i = 1; i <= sz; i++) {
        memo[i] = "";
    }
    sz = 0;
    
    return true;
}

int main() {
    
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    
    int Ans = 0;
    for (int l = 1; l <= n; l++) {
        if (check(l)) {
            Ans = l;
            break;
        }
    }
    
    cout << Ans;
    
    return 0;
}

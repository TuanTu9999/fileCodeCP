#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string t;
    getline(cin, t);
    char x = t[0];
    
    string s;
    getline(cin, s);
    
    string Ans = "";
    for (int i = 0; i <= s.size() - 1; i++) {
        if (s[i] != x) {
            Ans.push_back(s[i]);
        }
    }
    
    cout << Ans;
    
    return 0;
}

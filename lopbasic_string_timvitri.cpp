#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string t;
    getline(cin, t);
    
    char x = t[0];
    
    string s;
    getline(cin, s);
    
    int cnt = 0;
    for (int i = 0; i <= s.size() - 1; i++) {
        if (s[i] == x) {
            cnt++;
        }
    }
    
    cout << cnt << endl;
    
    for (int i = 0; i <= s.size() - 1; i++) {
        if (s[i] == x) {
            cout << i << " ";
        }
    }
    
    return 0;
}

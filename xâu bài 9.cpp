#include <bits/stdc++.h>

using namespace std;

int cnt[1000000]; // cnt i số lần xuất hiện của i

int main() {
    
    string s;
    getline(cin, s);
    
    for (int i = 0; i <= s.size() - 1; i++) {
        cnt[tolower(s[i])]++;
    }
    
    for (char c = 'a'; c <= 'z'; c++) {
        if (cnt[c] > 0) {
            cout << c << ' '<< cnt[c] << '\n';
        }
    }
    
    return 0;
}

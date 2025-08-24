#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

string s;
int c[300];
long long Ans;
stack<int> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME "mmass"
    if(fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    c['H'] = 1;
    c['C'] = 12;
    c['O'] = 16;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ')') {
            int sum = 0;
            while(!st.empty()) {
                int t = st.top();
                st.pop();
                if(t == '(' || st.empty()) break;
                sum += t;
            }
            st.push(sum);
        }
        else if(isdigit(s[i])) {
            int t = st.top() * (s[i] - 48);
            st.pop();
            st.push(t);
        }
        else if(s[i] == '(') st.push('(');
        else st.push(c[s[i]]);
    }
    while(st.size()) {
        Ans += st.top();
        st.pop();
    }
    cout << Ans;
    return 0;
}

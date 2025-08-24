#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int n, x;
long long Ans;
priority_queue<int, vector<int>, greater<int>> pQ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> x >> n;
    for(int i = 1; i <= n; i++) {
        int ai; cin >> ai;
        pQ.push(ai);
    }
    while(pQ.size() > 1) {
        int x = pQ.top();
        pQ.pop();
        int y = pQ.top();
        pQ.pop();
        Ans += x + y;
        pQ.push(x + y);
    }
    cout << Ans;
    return 0;
}

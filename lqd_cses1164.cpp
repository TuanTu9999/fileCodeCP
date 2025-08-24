#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

struct block {
    int l, r, id;
};

bool cmp(block a, block b) {
    return (a.l < b.l);
}

int n, pos[maxn], Ans;
block a[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        if(pQ.size()) {
            int mi = pQ.top().first, f = pQ.top().second;
            if(mi < a[i].l) {
                pos[a[i].id] = f;
                pQ.pop();
                pQ.push(pair<int, int>(a[i].r, f));
            }
            else {
                Ans++;
                pos[a[i].id] = Ans;
                pQ.push(pair<int, int>(a[i].r, Ans));
            }
        }
        else {
            Ans++;
            pos[a[i].id] = Ans;
            pQ.push(pair<int, int>(a[i].r, Ans));
        }
    }
    cout << Ans << '\n';
    for(int i = 1; i <= n; i++) cout << pos[i] << ' ';
    return 0;
}

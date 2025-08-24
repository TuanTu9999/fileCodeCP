#include <bits/stdc++.h>

using namespace std;

string s, a, b;
int k, pos[30], cnt;
vector<int> adj[30], cycle[30];
bool vis[30];

void DFS(int u) {
    vis[u] = 1;
    pos[u] = cnt;
    cycle[cnt].push_back(u);
    for (int v : adj[u]) {
        if (!vis[v]) DFS(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME "mahoaxau"
    if (fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }

    cin >> s >> k >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        int u = a[i] - 'a';
        int v = b[i] - 'a';
        adj[u].push_back(v);
    }

    memset(vis, 0, sizeof vis);
    for (int i = 0; i < 26; i++) {
        if (!vis[i]) {
            cnt++;
            DFS(i);
        }
    }

    for (char ch : s) {
        int u = ch - 'a';
        vector<int>& c = cycle[pos[u]];
        int idx = find(c.begin(), c.end(), u) - c.begin();
        int new_idx = (idx + k) % c.size();
        cout << (char)(c[new_idx] + 'a');
    }

    return 0;
}

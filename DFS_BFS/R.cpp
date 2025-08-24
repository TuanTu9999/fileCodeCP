#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int n;
vector<int> g[maxn], Ans;
bool vis[maxn];

void BFS(int u){
    vis[u] = 1;
    queue<int> q;
    q.push(u);
    while(q.size()){
        u = q.front();
        q.pop();
        for(int i = 1; i * i <= u; i++){
            if(u % i == 0){
                int b = u / i, v = (i - 1) * (b + 1);
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    BFS(n);
    for(int i = 0; i < n; i++) if(vis[i]) Ans.push_back(i);
    sort(Ans.begin(), Ans.end());
    Ans.resize(unique(Ans.begin(), Ans.end()) - Ans.begin());
    cout << Ans.size() << '\n';
    for(int x : Ans) cout << x << ' ';
    return 0;
}

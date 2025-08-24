#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

bool kt[(int)1e7 + 5];
int n;
vector<int> a;
deque<int> dq;

void sieve(int n){
    kt[0] = kt[1] = 1;
    for(int i = 2; i * i <= n; i++){
        if(!kt[i]){
            for(int j = i * i; j <= n; j += i) kt[j] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    sieve(1e7 + 3);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(!kt[x]) a.push_back(x);
    }
    if(a.empty()){
        cout << -1;
        return 0;
    }
    sort(a.begin(), a.end(), greater<int>());
    dq.push_back(a[0]);
    int pos = 0;
    for(int i = 1; i < (int)a.size(); i++, pos++){
        if(pos & 1) dq.push_back(a[i]);
        else dq.push_front(a[i]);
    }
    for(int x : dq) cout << x << ' ';
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
int q;
vector<long long> e;

void init(){
    for(long long i2 = 1; i2 <= inf; i2 *= 2){
        for(long long i3 = 1; i2 * i3 <= inf; i3 *= 3){
            for(long long i5 = 1; i2 * i3 * i5 <= inf; i5 *= 5){
                e.push_back(i2 * i3 * i5);
            }
        }
    }
    sort(e.begin(), e.end());
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    cin >> q;
    while(q--){
        long long x; cin >> x;
        int id = lower_bound(e.begin(), e.end(), x) - e.begin();
        if(e[id] == x) cout << id + 1 << '\n';
        else cout << "-1\n";
    }
    return 0;
}

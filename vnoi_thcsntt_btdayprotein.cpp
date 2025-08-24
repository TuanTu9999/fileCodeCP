#include <bits/stdc++.h>

using namespace std;

int n, ansCnt;
vector<string> ans;
string tmp;

void backtrack(int i){
    if(i == n){
        ansCnt++;
        ans.push_back(tmp);
        return;
    }

    for(int c = 65; c <= 67; c++){
        if(i == 0 || tmp[i - 1] != c){
            tmp[i] = c;
            backtrack(i + 1);
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
    tmp.resize(n);
    backtrack(0);
    sort(ans.begin(), ans.end());
    for(const string& x : ans) cout << x << '\n';
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;
char a[3];

void backtrack(int k, string s){
    if(k == n){
        cout << s << '\n';
        return;
    }

    for(int i = 0; i < 3; i++){
        if(s[k - 1] != a[i]){
            backtrack(k + 1, s + a[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    a[0] = 'A';
    a[1] = 'B';
    a[2] = 'C';
    backtrack(0, "");
    return 0;
}

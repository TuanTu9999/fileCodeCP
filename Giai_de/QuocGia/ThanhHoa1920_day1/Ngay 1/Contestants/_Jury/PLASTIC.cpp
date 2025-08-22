#include <bits/stdc++.h>
using namespace std;
int t,k,x;
int check(int x){
    int y;
    while (1){
        y = x;
        int cs[10] = {0};
        while (y>0){
            cs[y%10] = 1;
            y /=10;
        }
        int d = 0;
        for (int i=0;i<=9;i++)
            d+=cs[i];
        if (d<=k)
           return x;
        x++;
    }
}
int main(){
    freopen("PLASTIC.INP","r",stdin);
    freopen("PLASTIC.OUT","w",stdout);
    cin>>t;
    for (;t>0;t--){
        cin>>k;
        cin>>x;
        cout<<check(x)<<endl;
    }
}

#include <bits/stdc++.h>
#define NMAX 10
using namespace std;
bool cx[NMAX];
int n,k;
int main(){
    freopen("SCHEDULE.INP","w",stdout);
    srand(time(0));
    int t;
    cin>>t;
    cout<<t<<"\n";
    for (int ti=1;ti<=t;ti++){
        n = rand()%NMAX + 2;
        cout<<n<<"\n";

        for (int i=1; i<=n; i++){
            int m = rand()%n;
            for (int j=1; j<=n; j++)
                cx[j] = true;
            cx[i] = false;
            for (int j=1;j<=m;j++){
                do{
                    k = rand()% n + 1;
                } while (cx[k] == false);
                cout<<k<<" ";
                cx[k] = false;
            }
            cout<<0<<"\n";
        }

    }
    return 0;
}

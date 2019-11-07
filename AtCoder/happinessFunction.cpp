#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T, P, Q;
    cin >> T >> P >> Q;
    int X, Y;
    cin >> X >> Y;
    int res = 0;

    for (int i = 0; i < Q - P; ++i){
        int X_, Y_;
        cin >> X_ >> Y_;

        if(Y * Y_ < 0) res++;
        Y = Y_;
    }
    
    if(res >= T) cout << "Yes" << endl;
    else cout << "No" << endl;
}
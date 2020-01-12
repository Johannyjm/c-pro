#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    ll march[5] = {0};
    rep(i, n){
        string name;
        cin >> name;

        if(name[0]=='M') ++march[0];
        if(name[0]=='A') ++march[1];
        if(name[0]=='R') ++march[2];
        if(name[0]=='C') ++march[3];
        if(name[0]=='H') ++march[4];
        
    }

    ll res = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = i+1; j < 4; ++j){
            for(int k = j+1; k < 5; ++k){
                res += march[i] * march[j] * march[k];
            }
        }
    }

    cout << res << endl;
}
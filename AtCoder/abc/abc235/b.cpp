#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int now = 0;
    rep(i, n){
        int h;
        cin >> h;
        if(h <= now){
            cout << now << endl;
            return 0;
        }
        now = h;
    }
    cout << now << endl;

    return 0;
}
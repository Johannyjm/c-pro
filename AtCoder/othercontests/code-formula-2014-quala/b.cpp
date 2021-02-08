#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    vector<char> state(10, 'x');
    rep(i, a){
        int p;
        cin >> p;
        if(p == 0) p = 9;
        else --p;
        state[p] = '.';
    }
    rep(i, b){
        int q;
        cin >> q;
        if(q == 0) q = 9;
        else --q;
        state[q] = 'o';
    }

    for(int i = 6; i < 10; ++i) cout << state[i] << " ";
    cout << "\n ";
    for(int i = 3; i < 6; ++i) cout << state[i] << " ";
    cout << "\n  ";
    for(int i = 1; i < 3; ++i) cout << state[i] << " ";
    cout << "\n   " << state[0] << endl;

    return 0;
}
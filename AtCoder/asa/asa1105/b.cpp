#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<int> a(4);
    rep(i, 4) a[i] = s[i] - '0';
    const char o[2] = {'+', '-'};

    rep(i, 1<<3){
        vector<int> op(3, 0);
        rep(j, 3){
            if(i & (1<<j)) op[j] = 1;
        }

        int sm = a[0];
        rep(j, 3){
            if(op[j]==0) sm += a[j+1];
            else sm -= a[j+1];
        }

        if(sm == 7){
            rep(i, 3) cout << a[i] << o[op[i]];
            cout << a[3] << "=7" << endl;
            return 0;
        }
    }

    return 0;
}
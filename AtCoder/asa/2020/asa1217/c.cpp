#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> sm;
    sm.push_back(0);
    sm.push_back(0);
    rep1(i, n){
        int nxt = sm.back();
        if(s[i-1]=='A'&&s[i]=='C') ++nxt;
        sm.push_back(nxt);
    }


    rep(_, q){
        int l, r;
        cin >> l >> r;
        cout << sm[r] - sm[l] << endl;
    }

    return 0;
}
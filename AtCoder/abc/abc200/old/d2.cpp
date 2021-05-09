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
    vector<int> a;
    rep(i, n){
        int a_;
        cin >> a_;
        if(i < 8) a.push_back(a_ % 200);
    }

    n = min(n, 8);

    rep(i, pow(3, n)){
        vector<int> use(n, 0); // 0: nouse, 1: b, 2: c
        int tmp = i;
        rep(j, n){
            use[j] = tmp % 3;
            tmp /= 3;
        }
        // for(auto e: use) cout << e << " ";
        // cout << endl;
        vector<int> b, c;
        rep(j, n){
            if(use[j] == 1) b.push_back(j);
            if(use[j] == 2) c.push_back(j);
        }
        if(b.size() * c.size() == 0) continue;

        int smb = 0;
        int smc = 0;
        for(auto e: b) smb += a[e];
        for(auto e: c) smc += a[e];

        if(smb%200 == smc%200){
            cout << "Yes" << endl;
            cout << b.size() << " ";
            for(auto e: b) cout << e+1 << " ";
            cout << endl;
            cout << c.size() << " ";
            for(auto e: c) cout << e+1 << " ";
            cout << endl;
            return 0;
        }
    }

    cout << "No" << endl;


    return 0;
}
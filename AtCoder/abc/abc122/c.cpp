#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<int> cnt(n);
    cnt[0] = 0;
    rep(i, n-1){
        if(s[i] == 'A' && s[i+1] == 'C'){
            cnt[i+1] = cnt[i] + 1;
        }
        else cnt[i+1] = cnt[i];
    }
    // rep(i, n) cout << cnt[i] << " ";
    // cout << endl;

    rep(_, q){
        int l, r;
        cin >> l >> r;
        --l; --r;
        
        cout << cnt[r] - cnt[l] << endl; 
    }
}
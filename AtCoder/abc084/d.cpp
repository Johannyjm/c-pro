#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

bool is_prime(int n){
    if(n == 1) return false;
    
    for(int i = 2; i*i <= n; ++i){
        if(n%i == 0) return false;
    }

    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    vector<int> p_cnt(100001, 0);
    rep1(i, 100002){
        p_cnt[i] = p_cnt[i-1];
        if(i%2==1 && is_prime(i) && is_prime((i+1)/2)) ++p_cnt[i];
    }

    rep(_, q){
        int l, r;
        cin >> l >> r;

        cout << p_cnt[r] - p_cnt[l-1] << "\n";
    }


    return 0;
}
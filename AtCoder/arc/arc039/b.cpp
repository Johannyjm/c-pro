#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

vector<mint> fact, ifact, double_fact;
void init(int n) {
    fact.resize(n+1);
    ifact.resize(n+1);
    double_fact.resize(n+1);
    fact[0] = 1;

    for(int i = 1; i <= n; ++i) fact[i] = fact[i-1] * i;

    ifact[n] = fact[n].inv();
    for(int i = n; i >= 1; --i) ifact[i-1] = ifact[i] * i;

    double_fact[1] = 1;
    for(int i = 3; i <= n; i += 2) double_fact[i] = double_fact[i-2] * i;
}

mint comb(int n, int k){
    return fact[n] * ifact[k] * ifact[n-k];
}
mint perm(int n, int k){
    return fact[n] * ifact[n-k];
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    init(2200);

    int n, k;
    cin >> n >> k;

    int a = (k+n-1)/n;
    int b = k/n;

    if(b == 0){
        cout << comb(n+k-1, k).val() << endl;
        return 0;
    }

    if(k % n == 0){
        cout << 1 << endl;
        return 0;
    }

    int cnt_a = 0;
    rep1(i, n+1){
        if(k-a*i>0 && (k-a*i)%b==0){
            if(i+(k-a*i)/b != n) continue;
            // cout << i << endl;
            cnt_a = i;
        }
    }

    // cout << a << ": " << cnt_a << ", " << b << ": " << n-cnt_a << endl;
    cout << comb(n, cnt_a).val() << endl;

    return 0;
}
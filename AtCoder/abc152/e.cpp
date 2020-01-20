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

    map<int, int> prime_factor;
    map<int, int> prime_factors[n];
    set<int> primes;

    rep(i, n){
        int a;
        cin >> a;
        for (int j = 2; j*j <= a+6; ++j){
            int tmp = a;
            int cnt = 0;

            if(tmp%j)continue;

            while(tmp%j == 0){
                ++cnt;
                tmp /= j;
            }
            if(prime_factor[j] < cnt) prime_factor[j] = cnt;
            prime_factors[i][j] = cnt;
            primes.insert(j);
        }
    }

    for(auto prime: primes){
        cout << prime << endl;
    }
    return 0;

    int res = 0;
    const int MOD = 1000000007;
    rep(i, n){
        int sub = 1;
        
        for(auto prime: primes){
            cout << prime << endl;
            cout << prime_factor[prime] - prime_factors[i][prime] << endl;
            int p = prime_factor[prime] - prime_factors[i][prime];
            if(p) sub = (sub * p) % MOD;
        }

        res = (res + sub) % MOD;
    }

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    vector<int> a;
    int n;
    while(t--){
        cin >> n;
        a.resize(n);
        bool illegal = false;
        rep(i, n){
            cin >> a[i];
            if(a[i] == 1){
                illegal = true;
            }
        } 
        if(illegal){
            cout << -1 << endl;
            continue;
        }

        int res = 0;
        rep(i, n-1){
            if(gcd(a[i], a[i+1]) == 1) ++res;
        }

        cout << res << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
        if(i!=0){
            if(a[i] / 2 % 2 != a[i-1] / 2 % 2){
                cout << 0 << endl;
                return 0;
            }
        }
    }

    rep1(i, 15){
        int base = 2*i;
        vector<int> mul;
        mul.push_back(i);
        while(mul.size()!=50){
            int last =  mul.back();
            mul.push_back(last+base);
        }
        cout << i*2 << ":  ";
        rep(j, mul.size()) cout << mul[j] << " ";
        cout << endl;
    }


    return 0;
}
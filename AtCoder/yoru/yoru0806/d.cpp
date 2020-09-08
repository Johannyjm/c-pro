#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<int> a(n);
    ll mx_a = 0;
    ll mx_idx = -1;
    rep(i, n){
        cin >> a[i];
        if(a[i] > mx_a){
            mx_a = a[i];
            mx_idx = i;
        }
    }

    ll min_val = 1001001001;
    ll min_idx = -1;
    rep(i, n){
        if(i == mx_idx) continue;
        if(abs(mx_a - 2*a[i]) < min_val){
            min_val = abs(mx_a - 2*a[i]);
            min_idx = i;
        }
    }

    cout << mx_a << " " << a[min_idx] << endl;



    return 0;
}
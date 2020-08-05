#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> ab(n);
    ll res = 0;
    for(int i = 0; i < n; ++i){
        ll a, b;
        cin >> a >> b;
        ab[i] = a+b;
        res -= b;
    }

    sort(ab.begin(), ab.end(), greater<ll>());
    for(int i = 0; i < n; ++i){
        if(i%2 == 0) res += ab[i];
    }

    cout << res << endl;
}

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll sm_a = 0;
    ll sm_b = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sm_a += a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        sm_b += b[i];
    }

    ll cnt = sm_b - sm_a;

    ll c = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] < b[i]) c += (b[i]-a[i]+1)/2;
    }

    if(c <= cnt) cout << "Yes" << endl;
    else cout << "No" << endl;
}

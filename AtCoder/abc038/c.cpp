#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    ll l = 1;
    ll res = 0 ;
    for(int i = 1; i < n; ++i){
        if(a[i] > a[i-1]) ++l;
        else{
            res += l*(l+1)/2;
            l = 1;
        }
    }

    res += l*(l+1)/2;

    cout << res << endl;
}

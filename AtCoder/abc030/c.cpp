#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];

    ll now = 0;
    ll res = 0;
    bool at_a = true;
    while(1){
        if(at_a){
            int nxt = lower_bound(a.begin(), a.end(), now) - a.begin();
            if(nxt == n) break;
            now = a[nxt];
            now += x;
            at_a = false;
            ++res;
        }
        else{
            int nxt = lower_bound(b.begin(), b.end(), now) - b.begin();
            if(nxt == m) break;
            now = b[nxt];
            now += y;
            at_a = true;
            ++res;
        }
    }


    cout << res/2 << endl; 

    return 0;
}

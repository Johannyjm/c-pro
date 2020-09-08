#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, h;
    cin >> n >> h;

    vector<pair<ll, ll>> ab(n);
    ll a_mx = -1;
    ll a_idx= -1;
    for(int i = 0; i < n; ++i){
        ll a, b;
        cin >> a >> b;
        ab[i] = make_pair(b, a);
        if(a > a_mx){
            a_mx = a;
            a_idx = i;
        }
    }

    sort(ab.begin(), ab.end(), greater<pair<ll, ll>>());
    
    int res = 0;
    for(int i = 0; i < n; ++i){
        if(i == a_idx) continue;
        if(ab[i].first < a_mx) break;

        h -= ab[i].first;
        ++res;
        
        if(h <= 0){
            cout << res << endl;
            return 0;
        }
    }
    
    int slash = ab[a_idx].second;
    int thro = ab[a_idx].first;
    if(h <= thro) cout << res + 1 << endl;
    else cout << res+1 + ((h-thro) + slash - 1) / slash << endl;

    return 0;
}

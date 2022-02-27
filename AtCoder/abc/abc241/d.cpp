#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    set<ll> st;
    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            ll x;
            cin >> x;

            st.insert(x);
        }

        if(t == 2){
            ll x, k;
            cin >> x >> k;

            auto itr = st.lower_bound(x);

            if(itr - st.begin() < k){
                cout << -1 << "\n";
                continue;
            }

            for(int i = 0; i < k-1; ++i) --itr;

            cout << *itr << "\n";
        }

        if(t == 3){
            ll x, k;
            cin >> x >> k;

            auto itr = st.upper_bound(x);

            if(st.end() - itr > k){
                cout << -1 << "\n";
                continue;
            }
            for(int i = 0; i < k-1; ++i) ++itr;

            cout << *itr << "\n";            
        }
    }

    return 0;
}

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

    multiset<ll> st;
    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            ll x;
            cin >> x;

            st.insert(x);
        }

        if(t == 3){
            ll x, k;
            cin >> x >> k;

            auto itr = st.lower_bound(x);

            bool flg = false;
            for(int i = 0; i < k-1; ++i){
                if(itr == st.end()){
                    flg = true;
                    break;
                }
                ++itr;
            }
            if(itr == st.end()) flg = true;
        
            if(flg) cout << -1 << "\n";
            else cout << *itr << "\n";
        }

        if(t == 2){
            ll x, k;
            cin >> x >> k;

            auto itr = st.upper_bound(x);
            
            if(itr == st.begin()){
                cout << -1 << "\n";
                continue;
            }

            --itr;

            bool flg = false;
            for(int i = 0; i < k-1; ++i){
                if(itr == st.begin()){
                    flg = true;
                    break;
                }
                --itr;
            }

            if(flg) cout << -1 << "\n";
            else cout << *itr << "\n";
        }
    }

    return 0;
}

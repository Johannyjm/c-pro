#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int l, q;
    cin >> l >> q;

    set<int> st;
    st.insert(0);
    st.insert(l);
    while(q--){
        int c, x;
        cin >> c >> x;
        if(c == 1){
            st.insert(x);
        }

        if(c == 2){
            auto itr = st.lower_bound(x);
            int val = *itr;
            --itr;
            cout << val - *itr << endl;
        }
    }

    return 0;
}
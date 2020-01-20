#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    set<int> st;

    st.insert(1);
    st.insert(5);
    st.insert(2);
    st.insert(3);
    st.insert(5);

    for(auto ele: st){
        cout << ele << endl;
    }
    

    return 0;
}
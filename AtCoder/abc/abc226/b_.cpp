#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    unordered_set<int> st;
    rep(i, n){
        int l;
        int a[l];
        rep(i, l) cin >> a[i];
        st.insert(a);
    }

    cout << (int)st.size() << endl;

    return 0;
}
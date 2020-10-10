#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    set<int> st;
    int mn = 0;
    rep(i, n){
        st.insert(p[i]);

        while(st.find(mn) != st.end()) ++mn;

        cout << mn << "\n";
    }

    return 0;
}
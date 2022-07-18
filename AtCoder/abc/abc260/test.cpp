#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<string> s(n), t(m);
    rep(i, n) cin >> s[i];
    unordered_set<string> st;
    rep(j, m){
        cin >> t[j];
        st.insert(t[j]);
    }

    rep(i, n){
        if(st.count(s[i])){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }

    return 0;
}
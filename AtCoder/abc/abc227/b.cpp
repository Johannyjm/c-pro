#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unordered_set<int> st;
    rep1(a, 1000) rep1(b, 1000){
        int s = 4*a*b + 3*a + 3*b;
        if(s > 1000) continue;

        st.insert(s);
    }

    int n;
    cin >> n;
    int res = 0;
    rep(i, n){
        int s;
        cin >> s;
        if(st.count(s)) continue;
        ++res;
    }

    cout << res << endl;

    return 0;
}
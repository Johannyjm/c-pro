#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    rep(i, w){
        set<char> st;
        rep(j, h){
            st.insert(s[j][i]);
        }
        if(st.size() > (h+1)/2) {
            puts("No");
            return 0;
        }
    }

    rep(i, h){
        set<char> st;
        rep(j, w){
            st.insert(s[i][j]);
        }
        if(st.size() > (w+1)/2) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");


    return 0;
}
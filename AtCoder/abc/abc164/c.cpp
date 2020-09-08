#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    set<string> st;
    rep(i, n){
        string s;
        cin >> s;
        st.insert(s);
    }

    cout << (int)st.size() << endl;

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    if(s == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
        return 0;
    }

    set<char> st;
    vector<int> bucket(26, 0);
    rep(i, s.size()){
        st.insert(s[i]);
        ++bucket[s[i] - 'a'];
    }

    if(st.size() != 26){
        cout << s;
        rep(i, 26){
            if(bucket[i]) continue;
            cout << (char)(i + 'a') << endl;
            return 0;
        }
    }

    string res = s.substr(0, 25);
    vector<char> poped;
    poped.push_back(s[25]);
    
    for(int i = 25; i >= 0; --i){
        char bk = res.back();
        char target = 'z' + 1;

        rep(j, poped.size()){
            if(bk<poped[j]) target = min(target, poped[j]);
        }

        if(target <= 'z'){
            cout << res.substr(0, res.size()-1) << target << endl;
            return 0;
        }

        poped.push_back(res.back());
        res = res.substr(0, res.size()-1);
    }
    
    cout << res << endl;

    return 0;
}
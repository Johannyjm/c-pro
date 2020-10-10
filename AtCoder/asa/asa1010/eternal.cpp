#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int mod = 1000000007;
string s;
set<string> st;
ll dp[1010];
ll rec(int idx){

    if(dp[idx] > 0) return dp[idx];
    
    ll ret = 0;
    if(st.find(s.substr(0, idx)) != st.end()) ++ret;
    
    rep1(i, idx){
        string sub = s.substr(i, idx-i);
        if(st.find(sub) == st.end()) continue;

        ret = (ret + rec(i)) % mod;

    }

    return dp[idx] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n >> s;
    string t;

    rep(i, n){
        cin >> t;
        st.insert(t);
    }

    cout << rec((int)s.size()) << endl;

    return 0;
}
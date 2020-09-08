#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int mod = 1000000007;

unordered_set<string> st;
unordered_map<string, int> dp;

int rec(string s){
    if(dp[s] > 0) return dp[s];   
    int ret = 0;
    if(st.find(s) != st.end()) ++ret;
    int n = s.size();
    for(int i = 1; i < n; ++i){
        string sub1 = s.substr(0, i);
        string sub2 = s.substr(i+1, n-i);

        ret = (ret + rec(sub1)) % mod;
        ret = (ret + rec(sub2)) % mod;
    }

    return dp[s] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    
    for(int i = 0; i < n; ++i){
        string t;
        cin >> t;
        st.insert(t);
    }

    int res = rec(s);

    cout << res << endl;

    return 0;
    
}

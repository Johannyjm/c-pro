#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
const int mod = 1000000007;

string s;
unordered_set<string> st;

int dp[1010];
int rec(int idx){
    if(dp[idx] > 0) return dp[idx];
    
    int ret = 0;
    string sub = s.substr(0, idx);
    if(st.find(sub) != st.end()) ++ret;
    
    for(int i = 1; i < idx; ++i){
        string sub1 = sub.substr(i, idx-i);
        if(st.find(sub1) == st.end()) continue;
        ret = (ret + rec(i)) % mod;
    }

    return dp[idx] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n >> s;

    vector<string> t(n);
    for(int i = 0; i < n; ++i){
        cin >> t[i];
        st.insert(t[i]);
    }

    
    int m = s.size();
    cout << rec(m) << endl;

    return 0;
}

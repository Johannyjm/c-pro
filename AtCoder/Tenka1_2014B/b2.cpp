#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int mod = 1000000007;

unordered_map<string, bool> seen;
unordered_set<string> st;
int rec(string s, unordered_map<string, bool> seen){
    if(seen[s]) return -1;
    int ret = 0;
    if(st.find(s) != st.end()){
        ++ret;
        seen[s] = true;
    }

    int n = s.size();
    for(int i = 1; i < n; ++i){
        string sub1 = s.substr(0, i);
        string sub2 = s.substr(i, n-i);
        
        int ret1 = rec(sub1, seen);
        int ret2 = rec(sub2, seen);
        
        if(ret1!=-1 && ret2!=-1){
            ret = (ret + ret1) % mod;
            ret = (ret + ret2) % mod;
        }
    }

    return ret;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<string> t(n);
    for(int i = 0; i < n; ++i){
        cin >> t[i];
        st.insert(t[i]);
    }
    
    cout << rec(s, seen) << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int mypow(int n){
    int ret = 1;
    for(int i = 0; i < n; ++i) ret *= 10;
    return ret;
}

int s2i(string s){
    int ret = 0;
    int n = s.size();
    reverse(s.begin(), s.end());
    for(int i = 0; i < n; ++i){
        ret += (s[i] - '0') * mypow(i);
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<string> s;
    int m;
    while(true){
        string s_;
        cin >> s_;
        if('0' <= s_[0] && s_[0] <= '9'){
            m = s2i(s_);
            break;
        }
        s.push_back(s_);
    }
    int n = s.size();
    
    vector<string> t(m);
    for(int i = 0; i < m; ++i) cin >> t[i];

    vector<string> res(n);
    for(int i = 0; i < n; ++i){
        bool isng = false;
        for(int j = 0; j < m; ++j){
            if(s[i] == t[j]){
                isng = true;
                break;
            }
            string tmps = s[i];
            string tmpt = t[j];
            if(tmps.size() != tmpt.size()) continue;

            int l = tmps.size();
            for(int k = 0; k < l; ++k){
                if(tmpt[k] == '*'){
                    tmpt[k] = tmps[k];
                }
            }

            if(tmps == tmpt){
                isng = true;
                break;
            }
        }

        if(isng){
            string ans = "";
            for(int j = 0; j < (int)s[i].size(); ++j) ans += '*';
            res[i] = ans;
        }
        else res[i] = s[i];
    }

    for(int i = 0; i < n-1; ++i) cout << res[i] << " ";
    cout << res.back() << endl;
        
    return 0;
}

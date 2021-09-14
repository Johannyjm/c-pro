#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<string> s;
    string s_;
    int m;
    while(true){
        cin >> s_;
        if(!('0'<=s_[0] && s_[0]<='9')) s.push_back(s_);
        else{
            m = s_[0] - '0';
            break;
        }
    }
    int n = s.size();

    vector<string> t(m);
    for(int i = 0; i < m; ++i) cin >> t[i];

    vector<string> res;
    for(int i = 0; i < n; ++i){
        bool isng = false;
        for(int j = 0; j < m; ++j){
            
            if(s[i] == t[j]){
                isng = true;
                break;
            }

            if(s[i].size() != t[j].size()){
                isng = false;
                continue;
            }

            bool flg = false;
            for(int k = 0; k < (int)s[i].size(); ++k){
                if(t[j][k] == '*') continue;
                if(s[i][k] != t[j][k]){
                    flg = true;
                }
            }
            if(flg) continue;

            isng = true;
            
            // cout << s[i] << " " << t[j] << " " << isng << endl;
        }

        if(isng){
            string ans = "";
            for(int j = 0; j < (int)s[i].size(); ++j) ans += '*';
            res.push_back(ans);
        }
        else res.push_back(s[i]);
    }

    for(int i = 0; i < (int)res.size()-1; ++i) cout << res[i] << " ";
    cout << res.back() << endl;


}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    
    int n = s.size();
    int m = t.size();
    int t_idx = -1;
    for(int i = 0; i < n-m+1; ++i){
        bool flg = true;
        for(int j = 0; j < m; ++j){
            if(s[i+j]!='?' && s[i+j] != t[j]) flg = false;
        }

        if(flg) t_idx = i;
    }

    if(t_idx == -1) cout << "UNRESTORABLE" << endl;
    else{
        for(int i = 0; i < t_idx; ++i){
            if(s[i] == '?') cout << 'a';
            else cout << s[i];
        }
        cout << t;
        for(int i = t_idx+m; i < n; ++i){
            if(s[i] == '?') cout << 'a';
            else cout << s[i];
        }
        cout << endl;
    }
}

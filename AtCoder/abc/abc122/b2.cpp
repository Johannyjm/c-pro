#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
 
    string s;
    cin >> s;
    int n = s.size();
 
    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            string sub = s.substr(i, j-i+1);
            int num = sub.size();

            bool flg = true;
            for(int k = 0; i < num; ++k){
                char c = sub[k];
                if(c!='A' && c!='C' && c!='G' && c!='T') {
                    flg = false;
                }
            }
 
            if(flg) res = max(res, num);
        }
    }
 
    cout << res << endl;
 
 
    return 0;
}
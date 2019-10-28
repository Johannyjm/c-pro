#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    string res = "";

    for(int i = 0; i < s.length(); ++i){

        if(s[i] == '0' or s[i] == '1'){
            res += s[i];
        }
        else{

            if(res != ""){
                res.erase(res.length() - 1);
            }
        }
    }
    cout << res << endl;
}
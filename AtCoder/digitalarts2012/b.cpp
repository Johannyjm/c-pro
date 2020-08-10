#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    if(s == "a" || s == "zzzzzzzzzzzzzzzzzzzz"){
        cout << "NO" << endl;
        return 0;
    }

    int n = s.size();

    int hash = 0;
    for(int i = 0; i < n; ++i){
        hash += s[i] - 'a' + 1;
    }

    string res = "";
    while(hash){
        if(hash > 26){
            res += 'z';
            hash -= 26;
        }
        else{
            res += (char)('a' + hash - 1);
            hash = 0;
        }
    }

    if((n == 20 && s == res) || (res.back()=='a' && s == res)){
        char tmp = res.back();
        res.back() = res[n-2];
        res[n-2] = tmp;
    }
    if(n < 20 && s == res){
        --res.back();
        res += 'a';
    }

    cout << res << endl;

    return 0;

}

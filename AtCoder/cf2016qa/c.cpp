#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    int k;
    cin >> k;
    string res = "";

    for(int i = 0; i < n-1; ++i){
        int now = s[i] - 'a';
        if(26 - now > k || now == 0) res += s[i];
        else{
            res += 'a';
            k -= 26 - now;
        }
    }

    int last = s.back() - 'a';
    last += k;
    last %= 26;
    res += char('a' + last);

    cout << res << endl;

    return 0;
}

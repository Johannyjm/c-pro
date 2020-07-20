#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    map<char, int> mp_s, mp_t;
    string cnv_s = "";
    string cnv_t = "";
    int ptr_s = 0;
    int ptr_t = 0;
    for(int i = 0; i < s.size(); ++i){
        if(mp_s[s[i]] == 0){
            cnv_s += 'a' + ptr_s;
            mp_s[s[i]] = ptr_s+1;
            ++ptr_s;
        }
        else cnv_s += 'a' + mp_s[s[i]] - 1;

        if(mp_t[t[i]] == 0){
            cnv_t += 'a' + ptr_t;
            mp_t[t[i]] = ptr_t+1;
            ++ptr_t;
        }
        else cnv_t += 'a' + mp_t[t[i]] - 1;
    }

    if(cnv_s == cnv_t) puts("Yes");
    else puts("No");
    
}

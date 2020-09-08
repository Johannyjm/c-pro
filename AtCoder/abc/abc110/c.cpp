#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    
    vector<pair<char, int>> cnt_s, cnt_t;
    cnt_s.push_back(make_pair(s[0], 1));
    for(int i = 1; i < s.size(); ++i){
        if(cnt_s.back().first == s[i]) ++cnt_s.back().second;
        else cnt_s.push_back(make_pair(s[i], 1));
    }

    cnt_t.push_back(make_pair(t[0], 1));
    for(int i = 1; i < t.size(); ++i){
        if(cnt_t.back().first == t[i]) ++cnt_t.back().second;
        else cnt_t.push_back(make_pair(t[i], 1));
    }

    if(cnt_s.size() == cnt_t.size()){
        for(int i = 0; i < cnt_s.size(); ++i){
            if(cnt_s[i].second != cnt_t[i].second){
                puts("No");
                return 0;
            }
        }
        puts("Yes");
        return 0;
    }

    puts("No");

    return 0;
}

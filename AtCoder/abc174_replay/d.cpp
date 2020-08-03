#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int r_cnt = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'R') ++r_cnt;
    }

    int ng_r = 0;
    int ng_w = 0;
    for(int i = 0; i < n; ++i){
        if(i < r_cnt && s[i] == 'W') ++ng_w;
        if(i >= r_cnt && s[i] == 'R') ++ng_r;
    }

    cout << min(ng_w, ng_r) + abs(ng_w - ng_r) << endl;
}

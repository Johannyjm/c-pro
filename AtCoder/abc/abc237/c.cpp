#include <iostream>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool ispali(string s){
    int n = s.size();
    rep(i, n / 2){
        if(s[i] != s[n - i - 1]) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;

    if(ispali(s)){
        puts("Yes");
        return 0;
    }

    int n = s.size();
    int prea = 0;
    int sufa = 0;
    rep(i, n){
        if(s[i] == 'a') ++prea;
        else break;
    }

    for(int i = n-1; i >= 0; --i){
        if(s[i] == 'a') ++sufa;
        else break;
    }

    if(prea > sufa){
        puts("No");
        return 0;
    }

    int en = n-1;
    if(prea < sufa) en -= sufa - prea - 1;

    string s_ = "";
    for(int i = 0; i < en; ++i) s_ += s[i];

    if(ispali(s_)) puts("Yes");
    else puts("No");

    return 0;
}

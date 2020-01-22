#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int ptr = 0;
    string prev = s.substr(ptr, 1);
    int prelen = 1;
    ++ptr;
    int res = 1;
    while(ptr < s.size()-1){
        if(prev == s.substr(ptr, 1)){
            ++res;
            prev = s.substr(ptr, 2);
            ptr += 2;
            prelen = 2;
        }
        else{
            ++res;
            prev = s.substr(ptr, 1);
            ++ptr;
            prelen = 1;
        }
    }

    if(prelen == 1){
        if(s.substr(ptr, 1) != "" && prev != s.substr(ptr, 1)) ++res;
    }

    if(prelen == 2){
        if(s.substr(ptr, 2) != "" && prev != s.substr(ptr, 2)) ++res;
    }
  	

    cout << res << endl;

    return 0;
}
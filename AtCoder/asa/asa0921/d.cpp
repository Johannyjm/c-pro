#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

bool legal(string s){
    stack<int> st;
    for(char c: s){
        if(c == '(') st.push(1);
        else{
            if(st.empty()) return false;
            else st.pop();
        }
    }

    if(st.empty()) return true;
    else return false;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int st = 0;
    int st_ne = 0;
    for(char c: s){
        if(c == '(') ++st;
        else{
            if(st > 0) --st;
            else ++st_ne;
        }
    }



    string res = s;
    rep(i, st_ne) res = '(' + res;
    rep(i, st) res += ')';

    cout << res << endl;

    return 0;
}
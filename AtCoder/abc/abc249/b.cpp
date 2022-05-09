#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    bool all_lower = true;
    bool all_upper = true;
    unordered_set<char> st;
    for(auto c: s){
        if('A' <= c && c <= 'Z') all_lower = false;
        if('a' <= c && c <= 'z') all_upper = false;
        st.insert(c);
    }

    if(all_lower || all_upper || st.size() != s.size()){
        puts("No");
    }
    else{
        puts("Yes");
    }





    return 0;
}
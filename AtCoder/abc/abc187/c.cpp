#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    unordered_set<string> st;
    rep(i, n){
        string s;
        cin >> s;
        st.insert(s);
    }

    for(auto e: st){

        string other = '!' + e;
        if(st.count(other)){
            cout << e << endl;
            return 0;
        }
    }

    cout << "satisfiable" << endl;

    return 0;
}
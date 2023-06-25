#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    vector<char> st;
    int left = 0;
    for(char c: s){

        if(c == '('){
            ++left;
            st.push_back(c);
        }
        else if(c == ')' && left > 0){
            while(st.back() != '('){
                st.pop_back();
            }
            st.pop_back();
            --left;
        }
        else{
            st.push_back(c);
        }

    }

    for(char c: st){
        cout << c;
    }
    cout << endl;
    return 0;
}
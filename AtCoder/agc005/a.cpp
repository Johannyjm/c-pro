#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    stack<int> st;
    int res = s.size();
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'S'){
            st.push(1);
        }
        else{
            if(!st.empty()){
                st.pop();
                res -= 2;
            }
        }
    }

    cout << res << endl;

    return 0;
}

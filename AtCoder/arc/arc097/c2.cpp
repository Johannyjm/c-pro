#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int k;
    cin >> s >> k;

    int n = s.size();
    set<string> st;
    for(int i = 0; i < n; ++i){
        for(int j = 1; j < k+1; ++j){
            if(i+j <= n){
                string sub = s.substr(i, j);
//                cout << sub << endl;
                st.insert(sub);
            }
        }
    }
    
    auto itr = st.begin();
    for(int i = 0; i < k-1; ++i) ++itr;
    cout << *itr << endl;
}

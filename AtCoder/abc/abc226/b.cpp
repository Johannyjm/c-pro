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
        string str = "";
        int l;
        cin >> l;
        rep(j, l){
            int a;
            cin >> a;

            string sub = "";
            if(a == 0){
                sub = "0";
            }
            while(a){
                sub += a%10;
                a /= 10;
            }
            str += sub;
            str += ',';
        }
        
        st.insert(str);
    }

    cout << (int)st.size() << endl;

    return 0;
}
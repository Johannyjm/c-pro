#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, r;
    cin >> n >> r;
    string s;
    cin >> s;
    vector<char> c(n);
    int lastdot = -1;
    for(int i = 0; i < n; ++i){
        c[i] = s[i];
        if(c[i] == '.') lastdot = i;
    }
    
    if(lastdot == -1){
        cout << 0 << endl;
        return 0;
    }

    int res = max(0, lastdot-r+1) + 1;
    for(int i = 0; i < max(0, lastdot-r+1); ++i){
        if(c[i] == '.'){
            ++res;
            for(int j = 0; j < r; ++j){
                c[i+j] = 'o';
            }
        }
    }

    cout << res << endl;

    return 0;
}

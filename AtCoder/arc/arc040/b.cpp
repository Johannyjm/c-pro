#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, r;
    cin >> n >> r;
    string s;
    cin >> s;
    
    int ptr = s.size() - 1;
    bool active = false;
    int res = 0;
    while(ptr > 0){
        if(s[ptr] == '.'){
            if(active) res += r;
            else{
                active = true;
                ++res;
            }
            ptr -= r;
        }
        else{
            --ptr;
            if(active) ++res;
        }
    }

    cout << res << endl;

}
